#include <stdio.h>
#include <string.h>

#include "driver/sdspi_host.h"
#include "driver/spi_common.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_vfs_fat.h"
#include "sdmmc_cmd.h"

#define MOUNT_POINT "/sdcard"

#define PIN_NUM_MISO 13
#define PIN_NUM_MOSI 11
#define PIN_NUM_CLK 12
#define PIN_NUM_CS 10

static const char *TAG = "sd_card_test";

void app_main(void)
{

    esp_err_t ret;
    sdmmc_card_t *card = NULL;

    ESP_LOGI(TAG, "Initializing SD card over SPI");

    esp_vfs_fat_sdmmc_mount_config_t mount_config = {

        .format_if_mount_failed = false,
        .max_files = 5,
        .allocation_unit_size = 16 * 1024,

    };

    sdmmc_host_t host = SDSPI_HOST_DEFAULT();
    host.max_freq_khz = 4000;

    spi_bus_config_t bus_cfg = {
        .mosi_io_num = PIN_NUM_MOSI,
        .miso_io_num = PIN_NUM_MISO,
        .sclk_io_num = PIN_NUM_CLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = 4000,


    };
    ret = spi_bus_initialize(host.slot, &bus_cfg, SDSPI_DEFAULT_DMA);
    if(ret != ESP_OK)
    {
        ESP_LOGE(TAG,"Failed to initialize SPI bus:%s",esp_err_to_name(ret));
        return;
    }

    sdspi_device_config_t slot_config = SDSPI_DEVICE_CONFIG_DEFAULT();
    slot_config.gpio_cs = PIN_NUM_CS;
    slot_config.host_id = host.slot;

    ESP_LOGI(TAG,"Mounting filesystem");

    ret = esp_vfs_fat_sdspi_mount(
        MOUNT_POINT,
        &host,
        &slot_config,
        &mount_config,
        &card
    );

    if(ret != ESP_OK){

        ESP_LOGE(TAG,"Failed to mount SD card :%s",esp_err_to_name(ret));
        spi_bus_free(host.slot);
        return;
    }

    ESP_LOGI(TAG,"SD card mounted");
    sdmmc_card_print_info(stdout,card);

    const char *path = MOUNT_POINT "/hello.txt";
    ESP_LOGI(TAG,"Writing file:%s",path);

    FILE *f = fopen(path,"w");
    if(f == NULL){
        ESP_LOGE(TAG,"Failed to open file for writing");
        esp_vfs_fat_sdcard_unmount(MOUNT_POINT,card);
        spi_bus_free(host.slot);
        return;
    }

     fprintf(f,"ESP32-S3 SD card test OK\n");

     fclose(f);

     ESP_LOGI(TAG, "Reading file:%s",path);
     f = fopen(path,"r");

     if(f== NULL){

        ESP_LOGE(TAG,"Failed to open file for reading");
        esp_vfs_fat_sdcard_unmount(MOUNT_POINT,card);
        spi_bus_free(host.slot);
        return;
     }

     char line[64] = {0};
     fgets(line,sizeof(line),f);
     fclose(f);

    char *newline = strchr(line,'\n');
     if(newline != NULL){

        *newline = '\0';
     }

     ESP_LOGI(TAG,"Read from file:%s",line);
     esp_vfs_fat_sdcard_unmount(MOUNT_POINT,card);
     spi_bus_free(host.slot);

     ESP_LOGI(TAG,"SD card test finished");
}

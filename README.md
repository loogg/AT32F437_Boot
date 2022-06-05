# AT32F437 Bootloader

## 说明

  本仓库为基于 `RT-Thread v4.1.1` 版本实现的 AT32F437 Bootloader，识别 SPI Flash 中的固件并搬运到内部 Flash 中运行。

  使用 RT-Thread 固件打包工具将 bin 文件打包成 rbl 文件。该 Bootloader 不支持压缩和加密形式的固件。

  RT-Thread 固件打包工具在 tools 目录下。

  使用 `scons --target=mdk5 -s` 生成工程

## 资源占用

- MCU: AT32F437VMT7

- HSE: 12M

- SPI FLASH: W25Q128
  - SPI2:
    - PD1: SCK
    - PD3: MISO
    - PD4: MOSI
  - CS:
    - PD0

- 分区使用：

  | 分区 | Flash 设备 | 偏移地址 | 占用空间 |
  | ---- | ---- | ---- | ---- |
  | Bootloader | 内部 Flash | 0 | 64 * 1024 |
  | app | 内部 Flash | 64 * 1024 | 1 * 1024 * 1024 |
  | download | SPI Flash | 0 | 1 * 1024 * 1024 |

## 联系人信息

- 维护：马龙伟
- 邮箱：<2544047213@qq.com>

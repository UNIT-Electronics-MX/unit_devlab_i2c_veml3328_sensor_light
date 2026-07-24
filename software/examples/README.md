# Sensor Configuration

The VEML3328 provides several configurable parameters that allow the user to optimize measurement sensitivity, dynamic range, and conversion time according to the application requirements. All configuration settings are stored in the Configuration Register (0x00), which is a 16-bit register containing multiple user-programmable fields. The most important parameters for normal operation are the Digital Gain (DG), Analog Gain (GAIN), Integration Time (IT), and Sensitivity.

The Digital Gain (DG) is configured through bits [13:12] of the Configuration Register and adjusts the digital amplification applied to the measured signal. The sensor supports three selectable gain levels, with ×1 as the default setting.

<div align="center">

| **Field Value** | **Digital Gain** |
| ----------------|------------------|
| 00 | x1 |
| 01 | x2 |
| 10 | x4 |

</div>

The Analog Gain (GAIN) is configured through bits [11:10] of the Configuration Register. This setting controls the analog front-end sensitivity before analog-to-digital conversion, allowing the sensor to adapt to different illumination conditions. The available analog gain settings are shown below. 

<div align="center">

| **Field Value** | **Analog Gain** |
| ----------------|------------------|
| 11 | x^1/2 |
| 00 | x1 |
| 01 | x2 |
| 10 | x4 |

</div>

The Integration Time (IT) is configured through bits [5:4] of the Configuration Register and determines the duration of each measurement cycle. Increasing the integration time improves sensitivity under low-light conditions, while shorter integration times provide faster measurement updates.

<div align="center">

| **Field Value** | **Integration Time** |
| ----------------|------------------|
| 00 | 50 ms  |
| 01 | 100 ms |
| 10 | 200 ms |
| 11 | 400 ms |

</div>

Finally, the Sensitivity parameter is controlled by bit [6] of the Configuration Register. This setting selects the operating sensitivity of the sensor according to the application requirements. 

<div align="center">

| **Field Value** | **Sensitivity** |
| ----------------|------------------|
| 0 | High Sensitivity  |
| 1 | Low Sensitivity |

</div>

The measurement results for the Red, Green, Blue, Clear, and Infrared (IR) channels are stored in dedicated 16-bit data registers, which are described in the following section. 

# Data Registers

The VEML3328 stores each color measurement in a dedicated 16-bit read-only register. Each register is divided into a Low Byte (LSB) and a High Byte (MSB). The complete measurement is obtained by combining both bytes into a single 16-bit value.

The register organization is illustrated below.

<div align="center">

| **High Byte** | **Low Byte** |
| --------------|--------------|
| Bits [15:8]   | Bits [7:0]   |

</div>

The sensor independently measures the Red, Green, Blue, Clear, and Infrared (IR) channels. The corresponding data registers are listed in the following table.

## Measurement Data Registers

<div align="center">

| **Register** | **Address** | **Description** |
| -------------|-------------|-----------------|
| Clear Data   | 0x04        | 16-bit Clear channel measurement |
| Red Data     | 0x05        | 16-bit Red channel measurement   |
| Green Data   | 0x06        | 16-bit Green channel measurement |
| Blue Data    | 0x07        | 16-bit BLue channel measurement |
| Infrared (IR) Data   | 0x08        | 16-bit Infrared channel measurement |

</div>

Finally, the DevLab VEML3328 Arduino Library provides high-level functions that automatically read and combine these registers. However, understanding the register organization allows advanced users to configure the device directly through the I²C interface and implement custom applications.
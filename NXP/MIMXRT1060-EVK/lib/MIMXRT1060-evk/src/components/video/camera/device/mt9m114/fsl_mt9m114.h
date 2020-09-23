/*
 * Copyright  2017-2018 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_MT9M114_H_
#define _FSL_MT9M114_H_

#include "fsl_common.h"
#include "fsl_camera_device.h"
#include "fsl_video_i2c.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define MT9M114_I2C_ADDR 0x48
#define MT9M114_CHIP_ID  0x2481

/*! @brief MT9M114 register definitions.*/

/* 1.Core registers */
#define MT9M114_REG_Y_ADDR_START            0x3002
#define MT9M114_REG_X_ADDR_START            0x3004
#define MT9M114_REG_Y_ADDR_END              0x3006
#define MT9M114_REG_X_ADDR_END              0x3008
#define MT9M114_REG_FRAME_LENGTH_LINES      0x300A
#define MT9M114_REG_LINE_LENGTH_PCK_        0x300C
#define MT9M114_REG_COARSE_INTEGRATION_TIME 0x3012
#define MT9M114_REG_FINE_INTEGRATION_TIME   0x3014
#define MT9M114_REG_RESET_REGISTER          0x301A
#define MT9M114_REG_FLASH                   0x3046
#define MT9M114_REG_FLASH_COUNT             0x3048
#define MT9M114_REG_GREEN1_GAIN             0x3056
#define MT9M114_REG_BLUE_GAIN               0x3058
#define MT9M114_REG_RED_GAIN                0x305A
#define MT9M114_REG_GREEN2_GAIN             0x305C
#define MT9M114_REG_GLOBAL_GAIN             0x305E
#define MT9M114_REG_FUSE_ID1                0x31F4
#define MT9M114_REG_FUSE_ID2                0x31F6
#define MT9M114_REG_FUSE_ID3                0x31F8
#define MT9M114_REG_FUSE_ID4                0x31FA
#define MT9M114_REG_CHAIN_CONTROL           0x31FC
#define MT9M114_REG_CUSTOMER_REV            0x31FE

/* 2.SOC1 registers */
#define MT9M114_REG_COLOR_PIPELINE_CONTROL 0x3210

/* 3.SOC2 registers */
#define MT9M114_REG_P_G1_P0Q0     0x3640
#define MT9M114_REG_P_G1_P0Q1     0x3642
#define MT9M114_REG_P_G1_P0Q2     0x3644
#define MT9M114_REG_P_G1_P0Q3     0x3646
#define MT9M114_REG_P_G1_P0Q4     0x3648
#define MT9M114_REG_P_R_P0Q0      0x364A
#define MT9M114_REG_P_R_P0Q1      0x364C
#define MT9M114_REG_P_R_P0Q2      0x364E
#define MT9M114_REG_P_R_P0Q3      0x3650
#define MT9M114_REG_P_R_P0Q4      0x3652
#define MT9M114_REG_P_B_P0Q0      0x3654
#define MT9M114_REG_P_B_P0Q1      0x3656
#define MT9M114_REG_P_B_P0Q2      0x3658
#define MT9M114_REG_P_B_P0Q3      0x365A
#define MT9M114_REG_P_B_P0Q4      0x365C
#define MT9M114_REG_P_G2_P0Q0     0x365E
#define MT9M114_REG_P_G2_P0Q1     0x3660
#define MT9M114_REG_P_G2_P0Q2     0x3662
#define MT9M114_REG_P_G2_P0Q3     0x3664
#define MT9M114_REG_P_G2_P0Q4     0x3666
#define MT9M114_REG_P_G1_P1Q0     0x3680
#define MT9M114_REG_P_G1_P1Q1     0x3682
#define MT9M114_REG_P_G1_P1Q2     0x3684
#define MT9M114_REG_P_G1_P1Q3     0x3686
#define MT9M114_REG_P_G1_P1Q4     0x3688
#define MT9M114_REG_P_R_P1Q0      0x368A
#define MT9M114_REG_P_R_P1Q1      0x368C
#define MT9M114_REG_P_R_P1Q2      0x368E
#define MT9M114_REG_P_R_P1Q3      0x3690
#define MT9M114_REG_P_R_P1Q4      0x3692
#define MT9M114_REG_P_B_P1Q0      0x3694
#define MT9M114_REG_P_B_P1Q1      0x3696
#define MT9M114_REG_P_B_P1Q2      0x3698
#define MT9M114_REG_P_B_P1Q3      0x369A
#define MT9M114_REG_P_B_P1Q4      0x369C
#define MT9M114_REG_P_G2_P1Q0     0x369E
#define MT9M114_REG_P_G2_P1Q1     0x36A0
#define MT9M114_REG_P_G2_P1Q2     0x36A2
#define MT9M114_REG_P_G2_P1Q3     0x36A4
#define MT9M114_REG_P_G2_P1Q4     0x36A6
#define MT9M114_REG_P_G1_P2Q0     0x36C0
#define MT9M114_REG_P_G1_P2Q1     0x36C2
#define MT9M114_REG_P_G1_P2Q2     0x36C4
#define MT9M114_REG_P_G1_P2Q3     0x36C6
#define MT9M114_REG_P_G1_P2Q4     0x36C8
#define MT9M114_REG_P_R_P2Q0      0x36CA
#define MT9M114_REG_P_R_P2Q1      0x36CC
#define MT9M114_REG_P_R_P2Q2      0x36CE
#define MT9M114_REG_P_R_P2Q3      0x36D0
#define MT9M114_REG_P_R_P2Q4      0x36D2
#define MT9M114_REG_P_B_P2Q0      0x36D4
#define MT9M114_REG_P_B_P2Q1      0x36D6
#define MT9M114_REG_P_B_P2Q2      0x36D8
#define MT9M114_REG_P_B_P2Q3      0x36DA
#define MT9M114_REG_P_B_P2Q4      0x36DC
#define MT9M114_REG_P_G2_P2Q0     0x36DE
#define MT9M114_REG_P_G2_P2Q1     0x36E0
#define MT9M114_REG_P_G2_P2Q2     0x36E2
#define MT9M114_REG_P_G2_P2Q3     0x36E4
#define MT9M114_REG_P_G2_P2Q4     0x36E6
#define MT9M114_REG_P_G1_P3Q0     0x3700
#define MT9M114_REG_P_G1_P3Q1     0x3702
#define MT9M114_REG_P_G1_P3Q2     0x3704
#define MT9M114_REG_P_G1_P3Q3     0x3706
#define MT9M114_REG_P_G1_P3Q4     0x3708
#define MT9M114_REG_P_R_P3Q0      0x370A
#define MT9M114_REG_P_R_P3Q1      0x370C
#define MT9M114_REG_P_R_P3Q2      0x370E
#define MT9M114_REG_P_R_P3Q3      0x3710
#define MT9M114_REG_P_R_P3Q4      0x3712
#define MT9M114_REG_P_B_P3Q0      0x3714
#define MT9M114_REG_P_B_P3Q1      0x3716
#define MT9M114_REG_P_B_P3Q2      0x3718
#define MT9M114_REG_P_B_P3Q3      0x371A
#define MT9M114_REG_P_B_P3Q4      0x371C
#define MT9M114_REG_P_G2_P3Q0     0x371E
#define MT9M114_REG_P_G2_P3Q1     0x3720
#define MT9M114_REG_P_G2_P3Q2     0x3722
#define MT9M114_REG_P_G2_P3Q3     0x3724
#define MT9M114_REG_P_G2_P3Q4     0x3726
#define MT9M114_REG_P_G1_P4Q0     0x3740
#define MT9M114_REG_P_G1_P4Q1     0x3742
#define MT9M114_REG_P_G1_P4Q2     0x3744
#define MT9M114_REG_P_G1_P4Q3     0x3746
#define MT9M114_REG_P_G1_P4Q4     0x3748
#define MT9M114_REG_P_R_P4Q0      0x374A
#define MT9M114_REG_P_R_P4Q1      0x374C
#define MT9M114_REG_P_R_P4Q2      0x374E
#define MT9M114_REG_P_R_P4Q3      0x3750
#define MT9M114_REG_P_R_P4Q4      0x3752
#define MT9M114_REG_P_B_P4Q0      0x3754
#define MT9M114_REG_P_B_P4Q1      0x3756
#define MT9M114_REG_P_B_P4Q2      0x3758
#define MT9M114_REG_P_B_P4Q3      0x375A
#define MT9M114_REG_P_B_P4Q4      0x375C
#define MT9M114_REG_P_G2_P4Q0     0x375E
#define MT9M114_REG_P_G2_P4Q1     0x3760
#define MT9M114_REG_P_G2_P4Q2     0x3762
#define MT9M114_REG_P_G2_P4Q3     0x3764
#define MT9M114_REG_P_G2_P4Q4     0x3766
#define MT9M114_REG_CENTER_ROW    0x3782
#define MT9M114_REG_CENTER_COLUMN 0x3784

/* 4.SYSCTL registers */
#define MT9M114_REG_CHIP_ID                        0x0000
#define MT9M114_REG_CLOCKS_CONTROL                 0x0016
#define MT9M114_REG_RESET_AND_MISC_CONTROL         0x001A
#define MT9M114_REG_PAD_SLEW                       0x001E
#define MT9M114_REG_USER_DEFINED_DEVICE_ADDRESS_ID 0x002E
#define MT9M114_REG_PAD_CONTROL                    0x0032
#define MT9M114_REG_COMMAND_REGISTER               0x0080

/* 5.XDMA registers */
#define MT9M114_REG_ACCESS_CTL_STAT         0x0982
#define MT9M114_REG_PHYSICAL_ADDRESS_ACCESS 0x098A
#define MT9M114_REG_LOGICAL_ADDRESS_ACCESS  0x098E
#define MT9M114_REG_MCU_VARIABLE_DATA0      0x0990
#define MT9M114_REG_MCU_VARIABLE_DATA1      0x0992
#define MT9M114_REG_MCU_VARIABLE_DATA2      0x0994
#define MT9M114_REG_MCU_VARIABLE_DATA3      0x0996
#define MT9M114_REG_MCU_VARIABLE_DATA4      0x0998
#define MT9M114_REG_MCU_VARIABLE_DATA5      0x099A
#define MT9M114_REG_MCU_VARIABLE_DATA6      0x099C
#define MT9M114_REG_MCU_VARIABLE_DATA7      0x099E

/*! @brief MT9M114 variables definitions.*/

/* 01.Monitor variables */
#define MT9M114_VAR_MON_MAJOR_VERSION   0x8000
#define MT9M114_VAR_MON_MINOR_VERSION   0x8002
#define MT9M114_VAR_MON_RELEASE_VERSION 0x8004
#define MT9M114_VAR_MON_HEARTBEAT       0x8006

/* 02.Sequencer variables */
#define MT9M114_VAR_SEQ_ERROR_CODE 0x8406

/* 03.AE_Rule variables */
#define MT9M114_VAR_AE_RULE_ALGO                 0xA404
#define MT9M114_VAR_AE_RULE_AVG_Y_FROM_STATS     0xA406
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_0_0  0xA407
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_0_1  0xA408
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_0_2  0xA409
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_0_3  0xA40A
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_0_4  0xA40B
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_1_0  0xA40C
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_1_1  0xA40D
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_1_2  0xA40E
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_1_3  0xA40F
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_1_4  0xA410
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_2_0  0xA411
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_2_1  0xA412
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_2_2  0xA413
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_2_3  0xA414
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_2_4  0xA415
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_3_0  0xA416
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_3_1  0xA417
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_3_2  0xA418
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_3_3  0xA419
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_3_4  0xA41A
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_4_0  0xA41B
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_4_1  0xA41C
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_4_2  0xA41D
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_4_3  0xA41E
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_4_4  0xA41F
#define MT9M114_VAR_AE_RULE_AE_ADAPTIVE_STRENGTH 0xA420

/* 04.AE_Track variables */
#define MT9M114_VAR_AE_TRACK_STATUS                      0xA800
#define MT9M114_VAR_AE_TRACK_ALGO                        0xA804
#define MT9M114_VAR_AE_TRACK_TARGET_AVERAGE_LUMA         0xA807
#define MT9M114_VAR_AE_TRACK_GATE_PERCENTAGE             0xA808
#define MT9M114_VAR_AE_TRACK_CURRENT_AVERAGE_LUMA        0xA809
#define MT9M114_VAR_AE_TRACK_AE_TRACKING_DAMPENING_SPEED 0xA80A
#define MT9M114_VAR_AE_TRACK_AE_DAMPENING_SPEED          0xA80B
#define MT9M114_VAR_AE_TRACK_SKIP_FRAMES_COUNTER         0xA80D
#define MT9M114_VAR_AE_TRACK_CURRENT_FLICKER_LINES       0xA80E
#define MT9M114_VAR_AE_TRACK_FDZONE                      0xA818
#define MT9M114_VAR_AE_TRACK_ZONE                        0xA81B
#define MT9M114_VAR_AE_TRACK_FLICKER_LINES_50HZ          0xA826
#define MT9M114_VAR_AE_TRACK_VIRT_EXPOSURE_LOG           0xA828
#define MT9M114_VAR_AE_TRACK_MIN_VIRT_EXPOSURE_LOG_ZONE0 0xA82A
#define MT9M114_VAR_AE_TRACK_MAX_VIRT_EXPOSURE_LOG_ZONE0 0xA82C
#define MT9M114_VAR_AE_TRACK_MAX_VIRT_EXPOSURE_LOG_ZONE1 0xA82E
#define MT9M114_VAR_AE_TRACK_VIRT_GAIN                   0xA838

/* 05.AWB variables */
#define MT9M114_VAR_AWB_STATUS                        0xAC00
#define MT9M114_VAR_AWB_MODE                          0xAC02
#define MT9M114_VAR_AWB_R_RATIO_LOWER                 0xAC06
#define MT9M114_VAR_AWB_R_RATIO_UPPER                 0xAC07
#define MT9M114_VAR_AWB_B_RATIO_LOWER                 0xAC08
#define MT9M114_VAR_AWB_B_RATIO_UPPER                 0xAC09
#define MT9M114_VAR_AWB_R_SCENE_RATIO_LOWER           0xAC0A
#define MT9M114_VAR_AWB_R_SCENE_RATIO_UPPER           0xAC0B
#define MT9M114_VAR_AWB_B_SCENE_RATIO_LOWER           0xAC0C
#define MT9M114_VAR_AWB_B_SCENE_RATIO_UPPER           0xAC0D
#define MT9M114_VAR_AWB_R_RATIO_PRE_AWB               0xAC0E
#define MT9M114_VAR_AWB_B_RATIO_PRE_AWB               0xAC0F
#define MT9M114_VAR_AWB_R_GAIN                        0xAC12
#define MT9M114_VAR_AWB_B_GAIN                        0xAC14
#define MT9M114_VAR_AWB_PRE_AWB_RATIOS_TRACKING_SPEED 0xAC16
#define MT9M114_VAR_AWB_PIXEL_THRESHOLD_COUNT         0xAC18

/* 06.BlackLevel variables */
#define MT9M114_VAR_BLACKLEVEL_ALGO                  0xB004
#define MT9M114_VAR_BLACKLEVEL_MAX_BLACK_LEVEL       0xB00C
#define MT9M114_VAR_BLACKLEVEL_BLACK_LEVEL_DAMPENING 0xB00D

/* 07.CCM variables */
#define MT9M114_VAR_CCM_ALGO           0xB404
#define MT9M114_VAR_CCM_0              0xB406
#define MT9M114_VAR_CCM_1              0xB408
#define MT9M114_VAR_CCM_2              0xB40A
#define MT9M114_VAR_CCM_3              0xB40C
#define MT9M114_VAR_CCM_4              0xB40E
#define MT9M114_VAR_CCM_5              0xB410
#define MT9M114_VAR_CCM_6              0xB412
#define MT9M114_VAR_CCM_7              0xB414
#define MT9M114_VAR_CCM_8              0xB416
#define MT9M114_VAR_CCM_LL_DELTA_CCM_0 0xB418
#define MT9M114_VAR_CCM_LL_DELTA_CCM_1 0xB41A
#define MT9M114_VAR_CCM_LL_DELTA_CCM_2 0xB41C
#define MT9M114_VAR_CCM_LL_DELTA_CCM_3 0xB41E
#define MT9M114_VAR_CCM_LL_DELTA_CCM_4 0xB420
#define MT9M114_VAR_CCM_LL_DELTA_CCM_5 0xB422
#define MT9M114_VAR_CCM_LL_DELTA_CCM_6 0xB424
#define MT9M114_VAR_CCM_LL_DELTA_CCM_7 0xB426
#define MT9M114_VAR_CCM_LL_DELTA_CCM_8 0xB428
#define MT9M114_VAR_CCM_DELTA_GAIN     0xB42A
#define MT9M114_VAR_CCM_DELTA_THRESH   0xB42B

/* 08.LowLight variables */
#define MT9M114_VAR_LL_MODE                          0xBC02
#define MT9M114_VAR_LL_ALGO                          0xBC04
#define MT9M114_VAR_LL_GAMMA_SELECT                  0xBC07
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_0        0xBC0A
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_1        0xBC0B
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_2        0xBC0C
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_3        0xBC0D
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_4        0xBC0E
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_5        0xBC0F
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_6        0xBC10
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_7        0xBC11
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_8        0xBC12
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_9        0xBC13
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_10       0xBC14
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_11       0xBC15
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_12       0xBC16
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_13       0xBC17
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_14       0xBC18
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_15       0xBC19
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_16       0xBC1A
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_17       0xBC1B
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_18       0xBC1C
#define MT9M114_VAR_LL_GAMMA_NRCURVE_0               0xBC1D
#define MT9M114_VAR_LL_GAMMA_NRCURVE_1               0xBC1E
#define MT9M114_VAR_LL_GAMMA_NRCURVE_2               0xBC1F
#define MT9M114_VAR_LL_GAMMA_NRCURVE_3               0xBC20
#define MT9M114_VAR_LL_GAMMA_NRCURVE_4               0xBC21
#define MT9M114_VAR_LL_GAMMA_NRCURVE_5               0xBC22
#define MT9M114_VAR_LL_GAMMA_NRCURVE_6               0xBC23
#define MT9M114_VAR_LL_GAMMA_NRCURVE_7               0xBC24
#define MT9M114_VAR_LL_GAMMA_NRCURVE_8               0xBC25
#define MT9M114_VAR_LL_GAMMA_NRCURVE_9               0xBC26
#define MT9M114_VAR_LL_GAMMA_NRCURVE_10              0xBC27
#define MT9M114_VAR_LL_GAMMA_NRCURVE_11              0xBC28
#define MT9M114_VAR_LL_GAMMA_NRCURVE_12              0xBC29
#define MT9M114_VAR_LL_GAMMA_NRCURVE_13              0xBC2A
#define MT9M114_VAR_LL_GAMMA_NRCURVE_14              0xBC2B
#define MT9M114_VAR_LL_GAMMA_NRCURVE_15              0xBC2C
#define MT9M114_VAR_LL_GAMMA_NRCURVE_16              0xBC2D
#define MT9M114_VAR_LL_GAMMA_NRCURVE_17              0xBC2E
#define MT9M114_VAR_LL_GAMMA_NRCURVE_18              0xBC2F
#define MT9M114_VAR_LL_BM_PRECISION_BITS             0xBC31
#define MT9M114_VAR_LL_AVERAGE_LUMA_FADE_TO_BLACK    0xBC3A
#define MT9M114_VAR_LL_FADE_TO_BLACK_DAMPENING_SPEED 0xBC3C

/* 09.CameraControl variables */
#define MT9M114_VAR_CAM_SENSOR_CFG_Y_ADDR_START                0xC800
#define MT9M114_VAR_CAM_SENSOR_CFG_X_ADDR_START                0xC802
#define MT9M114_VAR_CAM_SENSOR_CFG_Y_ADDR_END                  0xC804
#define MT9M114_VAR_CAM_SENSOR_CFG_X_ADDR_END                  0xC806
#define MT9M114_VAR_CAM_SENSOR_CFG_PIXCLK                      0xC808
#define MT9M114_VAR_CAM_SENSOR_CFG_ROW_SPEED                   0xC80C
#define MT9M114_VAR_CAM_SENSOR_CFG_FINE_INTEG_TIME_MIN         0xC80E
#define MT9M114_VAR_CAM_SENSOR_CFG_FINE_INTEG_TIME_MAX         0xC810
#define MT9M114_VAR_CAM_SENSOR_CFG_FRAME_LENGTH_LINES          0xC812
#define MT9M114_VAR_CAM_SENSOR_CFG_LINE_LENGTH_PCK             0xC814
#define MT9M114_VAR_CAM_SENSOR_CFG_FINE_CORRECTION             0xC816
#define MT9M114_VAR_CAM_SENSOR_CFG_CPIPE_LAST_ROW              0xC818
#define MT9M114_VAR_CAM_SENSOR_CFG_REG_0_DATA                  0xC826
#define MT9M114_VAR_CAM_SENSOR_CONTROL_READ_MODE               0xC834
#define MT9M114_VAR_CAM_SENSOR_CONTROL_ANALOG_GAIN             0xC836
#define MT9M114_VAR_CAM_SENSOR_CONTROL_VIRT_COLUMN_GAIN        0xC838
#define MT9M114_VAR_CAM_SENSOR_CONTROL_FRAME_LENGTH_LINES      0xC83A
#define MT9M114_VAR_CAM_SENSOR_CONTROL_COARSE_INTEGRATION_TIME 0xC83C
#define MT9M114_VAR_CAM_SENSOR_CONTROL_FINE_INTEGRATION_TIME   0xC83E
#define MT9M114_VAR_CAM_CPIPE_CONTROL_DGAIN_RED                0xC840
#define MT9M114_VAR_CAM_CPIPE_CONTROL_DGAIN_GREEN1             0xC842
#define MT9M114_VAR_CAM_CPIPE_CONTROL_DGAIN_GREEN2             0xC844
#define MT9M114_VAR_CAM_CPIPE_CONTROL_DGAIN_BLUE               0xC846
#define MT9M114_VAR_CAM_CPIPE_CONTROL_DGAIN_SECOND             0xC848
#define MT9M114_VAR_CAM_CPIPE_CONTROL_SECOND_BLACK_LEVEL       0xC84B
#define MT9M114_VAR_CAM_MODE_SELECT                            0xC84C
#define MT9M114_VAR_CAM_MODE_TEST_PATTERN_SELECT               0xC84D
#define MT9M114_VAR_CAM_MODE_TEST_PATTERN_RED                  0xC84E
#define MT9M114_VAR_CAM_MODE_TEST_PATTERN_GREEN                0xC850
#define MT9M114_VAR_CAM_MODE_TEST_PATTERN_BLUE                 0xC852
#define MT9M114_VAR_CAM_CROP_WINDOW_XOFFSET                    0xC854
#define MT9M114_VAR_CAM_CROP_WINDOW_YOFFSET                    0xC856
#define MT9M114_VAR_CAM_CROP_WINDOW_WIDTH                      0xC858
#define MT9M114_VAR_CAM_CROP_WINDOW_HEIGHT                     0xC85A
#define MT9M114_VAR_CAM_CROP_CROPMODE                          0xC85C
#define MT9M114_VAR_CAM_SCALE_VERTICAL_TC_MODE                 0xC85E
#define MT9M114_VAR_CAM_SCALE_VERTICAL_TC_PERCENTAGE           0xC860
#define MT9M114_VAR_CAM_SCALE_VERTICAL_TC_STRETCH_FACTOR       0xC862
#define MT9M114_VAR_CAM_OUTPUT_WIDTH                           0xC868
#define MT9M114_VAR_CAM_OUTPUT_HEIGHT                          0xC86A
#define MT9M114_VAR_CAM_OUTPUT_FORMAT                          0xC86C
#define MT9M114_VAR_CAM_OUTPUT_FORMAT_YUV                      0xC86E
#define MT9M114_VAR_CAM_OUTPUT_Y_OFFSET                        0xC870
#define MT9M114_VAR_CAM_HUE_ANGLE                              0xC873
#define MT9M114_VAR_CAM_SFX_CONTROL                            0xC874
#define MT9M114_VAR_CAM_SFX_SOLARIZATION_THRESH                0xC875
#define MT9M114_VAR_CAM_SFX_SEPIA_CR                           0xC876
#define MT9M114_VAR_CAM_SFX_SEPIA_CB                           0xC877
#define MT9M114_VAR_CAM_AET_AEMODE                             0xC878
#define MT9M114_VAR_CAM_AET_SKIP_FRAMES                        0xC879
#define MT9M114_VAR_CAM_AET_TARGET_AVERAGE_LUMA                0xC87A
#define MT9M114_VAR_CAM_AET_TARGET_AVERAGE_LUMA_DARK           0xC87B
#define MT9M114_VAR_CAM_AET_BLACK_CLIPPING_TARGET              0xC87C
#define MT9M114_VAR_CAM_AET_AE_MIN_VIRT_INT_TIME_PCLK          0xC87E
#define MT9M114_VAR_CAM_AET_AE_MIN_VIRT_DGAIN                  0xC880
#define MT9M114_VAR_CAM_AET_AE_MAX_VIRT_DGAIN                  0xC882
#define MT9M114_VAR_CAM_AET_AE_MIN_VIRT_AGAIN                  0xC884
#define MT9M114_VAR_CAM_AET_AE_MAX_VIRT_AGAIN                  0xC886
#define MT9M114_VAR_CAM_AET_AE_VIRT_GAIN_TH_EG                 0xC888
#define MT9M114_VAR_CAM_AET_AE_EG_GATE_PERCENTAGE              0xC88A
#define MT9M114_VAR_CAM_AET_FLICKER_FREQ_HZ                    0xC88B
#define MT9M114_VAR_CAM_AET_MAX_FRAME_RATE                     0xC88C
#define MT9M114_VAR_CAM_AET_MIN_FRAME_RATE                     0xC88E
#define MT9M114_VAR_CAM_AET_TARGET_GAIN                        0xC890
#define MT9M114_VAR_CAM_AWB_CCM_L_0                            0xC892
#define MT9M114_VAR_CAM_AWB_CCM_L_1                            0xC894
#define MT9M114_VAR_CAM_AWB_CCM_L_2                            0xC896
#define MT9M114_VAR_CAM_AWB_CCM_L_3                            0xC898
#define MT9M114_VAR_CAM_AWB_CCM_L_4                            0xC89A
#define MT9M114_VAR_CAM_AWB_CCM_L_5                            0xC89C
#define MT9M114_VAR_CAM_AWB_CCM_L_6                            0xC89E
#define MT9M114_VAR_CAM_AWB_CCM_L_7                            0xC8A0
#define MT9M114_VAR_CAM_AWB_CCM_L_8                            0xC8A2
#define MT9M114_VAR_CAM_AWB_CCM_M_0                            0xC8A4
#define MT9M114_VAR_CAM_AWB_CCM_M_1                            0xC8A6
#define MT9M114_VAR_CAM_AWB_CCM_M_2                            0xC8A8
#define MT9M114_VAR_CAM_AWB_CCM_M_3                            0xC8AA
#define MT9M114_VAR_CAM_AWB_CCM_M_4                            0xC8AC
#define MT9M114_VAR_CAM_AWB_CCM_M_5                            0xC8AE
#define MT9M114_VAR_CAM_AWB_CCM_M_6                            0xC8B0
#define MT9M114_VAR_CAM_AWB_CCM_M_7                            0xC8B2
#define MT9M114_VAR_CAM_AWB_CCM_M_8                            0xC8B4
#define MT9M114_VAR_CAM_AWB_CCM_R_0                            0xC8B6
#define MT9M114_VAR_CAM_AWB_CCM_R_1                            0xC8B8
#define MT9M114_VAR_CAM_AWB_CCM_R_2                            0xC8BA
#define MT9M114_VAR_CAM_AWB_CCM_R_3                            0xC8BC
#define MT9M114_VAR_CAM_AWB_CCM_R_4                            0xC8BE
#define MT9M114_VAR_CAM_AWB_CCM_R_5                            0xC8C0
#define MT9M114_VAR_CAM_AWB_CCM_R_6                            0xC8C2
#define MT9M114_VAR_CAM_AWB_CCM_R_7                            0xC8C4
#define MT9M114_VAR_CAM_AWB_CCM_R_8                            0xC8C6
#define MT9M114_VAR_CAM_AWB_CCM_L_RG_GAIN                      0xC8C8
#define MT9M114_VAR_CAM_AWB_CCM_L_BG_GAIN                      0xC8CA
#define MT9M114_VAR_CAM_AWB_CCM_M_RG_GAIN                      0xC8CC
#define MT9M114_VAR_CAM_AWB_CCM_M_BG_GAIN                      0xC8CE
#define MT9M114_VAR_CAM_AWB_CCM_R_RG_GAIN                      0xC8D0
#define MT9M114_VAR_CAM_AWB_CCM_R_BG_GAIN                      0xC8D2
#define MT9M114_VAR_CAM_AWB_CCM_L_CTEMP                        0xC8D4
#define MT9M114_VAR_CAM_AWB_CCM_M_CTEMP                        0xC8D6
#define MT9M114_VAR_CAM_AWB_CCM_R_CTEMP                        0xC8D8
#define MT9M114_VAR_CAM_AWB_LL_CCM_0                           0xC8DA
#define MT9M114_VAR_CAM_AWB_LL_CCM_1                           0xC8DC
#define MT9M114_VAR_CAM_AWB_LL_CCM_2                           0xC8DE
#define MT9M114_VAR_CAM_AWB_LL_CCM_3                           0xC8E0
#define MT9M114_VAR_CAM_AWB_LL_CCM_4                           0xC8E2
#define MT9M114_VAR_CAM_AWB_LL_CCM_5                           0xC8E4
#define MT9M114_VAR_CAM_AWB_LL_CCM_6                           0xC8E6
#define MT9M114_VAR_CAM_AWB_LL_CCM_7                           0xC8E8
#define MT9M114_VAR_CAM_AWB_LL_CCM_8                           0xC8EA
#define MT9M114_VAR_CAM_AWB_COLOR_TEMPERATURE_MIN              0xC8EC
#define MT9M114_VAR_CAM_AWB_COLOR_TEMPERATURE_MAX              0xC8EE
#define MT9M114_VAR_CAM_AWB_COLOR_TEMPERATURE                  0xC8F0
#define MT9M114_VAR_CAM_AWB_AWB_XSCALE                         0xC8F2
#define MT9M114_VAR_CAM_AWB_AWB_YSCALE                         0xC8F3
#define MT9M114_VAR_CAM_AWB_AWB_WEIGHTS_0                      0xC8F4
#define MT9M114_VAR_CAM_AWB_AWB_WEIGHTS_1                      0xC8F6
#define MT9M114_VAR_CAM_AWB_AWB_WEIGHTS_2                      0xC8F8
#define MT9M114_VAR_CAM_AWB_AWB_WEIGHTS_3                      0xC8FA
#define MT9M114_VAR_CAM_AWB_AWB_WEIGHTS_4                      0xC8FC
#define MT9M114_VAR_CAM_AWB_AWB_WEIGHTS_5                      0xC8FE
#define MT9M114_VAR_CAM_AWB_AWB_WEIGHTS_6                      0xC900
#define MT9M114_VAR_CAM_AWB_AWB_WEIGHTS_7                      0xC902
#define MT9M114_VAR_CAM_AWB_AWB_XSHIFT_PRE_ADJ                 0xC904
#define MT9M114_VAR_CAM_AWB_AWB_YSHIFT_PRE_ADJ                 0xC906
#define MT9M114_VAR_CAM_AWB_AWBMODE                            0xC909
#define MT9M114_VAR_CAM_AWB_TINTS_CTEMP_THRESHOLD              0xC90A
#define MT9M114_VAR_CAM_AWB_K_R_L                              0xC90C
#define MT9M114_VAR_CAM_AWB_K_G_L                              0xC90D
#define MT9M114_VAR_CAM_AWB_K_B_L                              0xC90E
#define MT9M114_VAR_CAM_AWB_K_R_R                              0xC90F
#define MT9M114_VAR_CAM_AWB_K_G_R                              0xC910
#define MT9M114_VAR_CAM_AWB_K_B_R                              0xC911
#define MT9M114_VAR_CAM_STAT_AWB_CLIP_WINDOW_XSTART            0xC914
#define MT9M114_VAR_CAM_STAT_AWB_CLIP_WINDOW_YSTART            0xC916
#define MT9M114_VAR_CAM_STAT_AWB_CLIP_WINDOW_XEND              0xC918
#define MT9M114_VAR_CAM_STAT_AWB_CLIP_WINDOW_YEND              0xC91A
#define MT9M114_VAR_CAM_STAT_AE_INITIAL_WINDOW_XSTART          0xC91C
#define MT9M114_VAR_CAM_STAT_AE_INITIAL_WINDOW_YSTART          0xC91E
#define MT9M114_VAR_CAM_STAT_AE_INITIAL_WINDOW_XEND            0xC920
#define MT9M114_VAR_CAM_STAT_AE_INITIAL_WINDOW_YEND            0xC922
#define MT9M114_VAR_CAM_LL_LLMODE                              0xC924
#define MT9M114_VAR_CAM_LL_START_BRIGHTNESS                    0xC926
#define MT9M114_VAR_CAM_LL_STOP_BRIGHTNESS                     0xC928
#define MT9M114_VAR_CAM_LL_START_SATURATION                    0xC92A
#define MT9M114_VAR_CAM_LL_END_SATURATION                      0xC92B
#define MT9M114_VAR_CAM_LL_START_DESATURATION                  0xC92C
#define MT9M114_VAR_CAM_LL_END_DESATURATION                    0xC92D
#define MT9M114_VAR_CAM_LL_START_DEMOSAIC                      0xC92E
#define MT9M114_VAR_CAM_LL_START_AP_GAIN                       0xC92F
#define MT9M114_VAR_CAM_LL_START_AP_THRESH                     0xC930
#define MT9M114_VAR_CAM_LL_STOP_DEMOSAIC                       0xC931
#define MT9M114_VAR_CAM_LL_STOP_AP_GAIN                        0xC932
#define MT9M114_VAR_CAM_LL_STOP_AP_THRESH                      0xC933
#define MT9M114_VAR_CAM_LL_START_NR_RED                        0xC934
#define MT9M114_VAR_CAM_LL_START_NR_GREEN                      0xC935
#define MT9M114_VAR_CAM_LL_START_NR_BLUE                       0xC936
#define MT9M114_VAR_CAM_LL_START_NR_THRESH                     0xC937
#define MT9M114_VAR_CAM_LL_STOP_NR_RED                         0xC938
#define MT9M114_VAR_CAM_LL_STOP_NR_GREEN                       0xC939
#define MT9M114_VAR_CAM_LL_STOP_NR_BLUE                        0xC93A
#define MT9M114_VAR_CAM_LL_STOP_NR_THRESH                      0xC93B
#define MT9M114_VAR_CAM_LL_START_CONTRAST_BM                   0xC93C
#define MT9M114_VAR_CAM_LL_STOP_CONTRAST_BM                    0xC93E
#define MT9M114_VAR_CAM_LL_GAMMA                               0xC940
#define MT9M114_VAR_CAM_LL_START_CONTRAST_GRADIENT             0xC942
#define MT9M114_VAR_CAM_LL_STOP_CONTRAST_GRADIENT              0xC943
#define MT9M114_VAR_CAM_LL_START_CONTRAST_LUMA_PERCENTAGE      0xC944
#define MT9M114_VAR_CAM_LL_STOP_CONTRAST_LUMA_PERCENTAGE       0xC945
#define MT9M114_VAR_CAM_LL_START_GAIN_METRIC                   0xC946
#define MT9M114_VAR_CAM_LL_STOP_GAIN_METRIC                    0xC948
#define MT9M114_VAR_CAM_LL_START_FADE_TO_BLACK_LUMA            0xC94A
#define MT9M114_VAR_CAM_LL_STOP_FADE_TO_BLACK_LUMA             0xC94C
#define MT9M114_VAR_CAM_LL_CLUSTER_DC_TH_BM                    0xC94E
#define MT9M114_VAR_CAM_LL_CLUSTER_DC_GATE_PERCENTAGE          0xC950
#define MT9M114_VAR_CAM_LL_SUMMING_SENSITIVITY_FACTOR          0xC951
#define MT9M114_VAR_CAM_LL_START_TARGET_LUMA_BM                0xC952
#define MT9M114_VAR_CAM_LL_STOP_TARGET_LUMA_BM                 0xC954
#define MT9M114_VAR_CAM_LL_INV_BRIGHTNESS_METRIC               0xC956
#define MT9M114_VAR_CAM_LL_GAIN_METRIC                         0xC958
#define MT9M114_VAR_CAM_SEQ_UV_COLOR_BOOST                     0xC95A
#define MT9M114_VAR_CAM_PGA_PGA_CONTROL                        0xC95E
#define MT9M114_VAR_CAM_PGA_L_CONFIG_COLOUR_TEMP               0xC960
#define MT9M114_VAR_CAM_PGA_L_CONFIG_GREEN_RED_Q14             0xC962
#define MT9M114_VAR_CAM_PGA_L_CONFIG_RED_Q14                   0xC964
#define MT9M114_VAR_CAM_PGA_L_CONFIG_GREEN_BLUE_Q14            0xC966
#define MT9M114_VAR_CAM_PGA_L_CONFIG_BLUE_Q14                  0xC968
#define MT9M114_VAR_CAM_PGA_M_CONFIG_COLOUR_TEMP               0xC96A
#define MT9M114_VAR_CAM_PGA_M_CONFIG_GREEN_RED_Q14             0xC96C
#define MT9M114_VAR_CAM_PGA_M_CONFIG_RED_Q14                   0xC96E
#define MT9M114_VAR_CAM_PGA_M_CONFIG_GREEN_BLUE_Q14            0xC970
#define MT9M114_VAR_CAM_PGA_M_CONFIG_BLUE_Q14                  0xC972
#define MT9M114_VAR_CAM_PGA_R_CONFIG_COLOUR_TEMP               0xC974
#define MT9M114_VAR_CAM_PGA_R_CONFIG_GREEN_RED_Q14             0xC976
#define MT9M114_VAR_CAM_PGA_R_CONFIG_RED_Q14                   0xC978
#define MT9M114_VAR_CAM_PGA_R_CONFIG_GREEN_BLUE_Q14            0xC97A
#define MT9M114_VAR_CAM_PGA_R_CONFIG_BLUE_Q14                  0xC97C
#define MT9M114_VAR_CAM_SYSCTL_PLL_ENABLE                      0xC97E
#define MT9M114_VAR_CAM_SYSCTL_PLL_DIVIDER_M_N                 0xC980
#define MT9M114_VAR_CAM_SYSCTL_PLL_DIVIDER_P                   0xC982
#define MT9M114_VAR_CAM_PORT_OUTPUT_CONTROL                    0xC984
#define MT9M114_VAR_CAM_PORT_PORCH                             0xC986
#define MT9M114_VAR_CAM_PORT_MIPI_TIMING_T_HS_ZERO             0xC988
#define MT9M114_VAR_CAM_PORT_MIPI_TIMING_T_HS_EXIT_HS_TRAIL    0xC98A
#define MT9M114_VAR_CAM_PORT_MIPI_TIMING_T_CLK_POST_CLK_PRE    0xC98C
#define MT9M114_VAR_CAM_PORT_MIPI_TIMING_T_CLK_TRAIL_CLK_ZERO  0xC98E
#define MT9M114_VAR_CAM_PORT_MIPI_TIMING_T_LPX                 0xC990
#define MT9M114_VAR_CAM_PORT_MIPI_TIMING_INIT_TIMING           0xC992

/* 10.UVC_Control variables */
#define MT9M114_VAR_UVC_AE_MODE_CONTROL                        0xCC00
#define MT9M114_VAR_UVC_WHITE_BALANCE_TEMPERATURE_AUTO_CONTROL 0xCC01
#define MT9M114_VAR_UVC_AE_PRIORITY_CONTROL                    0xCC02
#define MT9M114_VAR_UVC_POWER_LINE_FREQUENCY_CONTROL           0xCC03
#define MT9M114_VAR_UVC_EXPOSURE_TIME_ABSOLUTE_CONTROL         0xCC04
#define MT9M114_VAR_UVC_BACKLIGHT_COMPENSATION_CONTROL         0xCC08
#define MT9M114_VAR_UVC_BRIGHTNESS_CONTROL                     0xCC0A
#define MT9M114_VAR_UVC_CONTRAST_CONTROL                       0xCC0C
#define MT9M114_VAR_UVC_GAIN_CONTROL                           0xCC0E
#define MT9M114_VAR_UVC_HUE_CONTROL                            0xCC10
#define MT9M114_VAR_UVC_SATURATION_CONTROL                     0xCC12
#define MT9M114_VAR_UVC_SHARPNESS_CONTROL                      0xCC14
#define MT9M114_VAR_UVC_GAMMA_CONTROL                          0xCC16
#define MT9M114_VAR_UVC_WHITE_BALANCE_TEMPERATURE_CONTROL      0xCC18
#define MT9M114_VAR_UVC_FRAME_INTERVAL_CONTROL                 0xCC1C
#define MT9M114_VAR_UVC_MANUAL_EXPOSURE_CONFIGURATION          0xCC20
#define MT9M114_VAR_UVC_FLICKER_AVOIDANCE_CONFIGURATION        0xCC21
#define MT9M114_VAR_UVC_ALGO                                   0xCC22
#define MT9M114_VAR_UVC_RESULT_STATUS                          0xCC24

/* 11.SystemManager variables */
#define MT9M114_VAR_SYSMGR_NEXT_STATE    0xDC00
#define MT9M114_VAR_SYSMGR_CURRENT_STATE 0xDC01
#define MT9M114_VAR_SYSMGR_CMD_STATUS    0xDC02

/* 12.PatchLoader variables */
#define MT9M114_VAR_PATCHLDR_LOADER_ADDRESS 0xE000
#define MT9M114_VAR_PATCHLDR_PATCH_ID       0xE002
#define MT9M114_VAR_PATCHLDR_FIRMWARE_ID    0xE004
#define MT9M114_VAR_PATCHLDR_APPLY_STATUS   0xE008
#define MT9M114_VAR_PATCHLDR_NUM_PATCHES    0xE009
#define MT9M114_VAR_PATCHLDR_PATCH_ID_0     0xE00A
#define MT9M114_VAR_PATCHLDR_PATCH_ID_1     0xE00C
#define MT9M114_VAR_PATCHLDR_PATCH_ID_2     0xE00E
#define MT9M114_VAR_PATCHLDR_PATCH_ID_3     0xE010
#define MT9M114_VAR_PATCHLDR_PATCH_ID_4     0xE012
#define MT9M114_VAR_PATCHLDR_PATCH_ID_5     0xE014
#define MT9M114_VAR_PATCHLDR_PATCH_ID_6     0xE016
#define MT9M114_VAR_PATCHLDR_PATCH_ID_7     0xE018

/* 13.Patch variables */
#define MT9M114_VAR_PATCHVARS_DELTA_DK_CORRECTION_FACTOR 0xE400

/* 14.CommandHandler variables */
#define MT9M114_VAR_CMD_HANDLER_WAIT_EVENT_ID 0xFC00
#define MT9M114_VAR_CMD_HANDLER_NUM_EVENTS    0xFC02

/*! @brief MT9M114 command definitions. */
#define MT9M114_COMMAND_APPLY_PATCH    0x0001
#define MT9M114_COMMAND_SET_STATE      0x0002
#define MT9M114_COMMAND_REFRESH        0x0004
#define MT9M114_COMMAND_WAIT_FOR_EVENT 0x0008
#define MT9M114_COMMAND_OK             0x8000

/*! @brief MT9M114 system state definitions. */
#define MT9M114_SYS_STATE_ENTER_CONFIG_CHANGE 0x28
#define MT9M114_SYS_STATE_STREAMING           0x31
#define MT9M114_SYS_STATE_START_STREAMING     0x34
#define MT9M114_SYS_STATE_ENTER_SUSPEND       0x40
#define MT9M114_SYS_STATE_SUSPENDED           0x41
#define MT9M114_SYS_STATE_ENTER_STANDBY       0x50
#define MT9M114_SYS_STATE_STANDBY             0x52
#define MT9M114_SYS_STATE_LEAVE_STANDBY       0x54

/*! @brief MT9M114 system set-state command retults. */
#define MT9M114_SYS_STATE_SET_RESULT_ENOERR 0x00 /* command successful */
#define MT9M114_SYS_STATE_SET_RESULTEINVAL  0x0C /* invalid configuration */
#define MT9M114_SYS_STATE_SET_RESULTENOSPC  0x0D /* resource not available */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief MT9M114 resource.
 *
 * Before initialize the MT9M114, the resource must be initialized that the
 * Two-Wire-Serial-Interface I2C could start to work.
 */
typedef struct _mt9m114_resource
{
    video_i2c_send_func_t i2cSendFunc;       /*!< I2C send function. */
    video_i2c_receive_func_t i2cReceiveFunc; /*!< I2C receive function. */
    void (*pullResetPin)(bool pullUp);       /*!< Function to pull reset pin high or low. */
    uint32_t inputClockFreq_Hz;              /*!< Input clock frequency, EXTCLK. */
} mt9m114_resource_t;

/*! @brief MT9M114 operation functions. */
extern const camera_device_operations_t mt9m114_ops;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif /* _FSL_MT9M114_H_ */

EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:+5V #PWR0101
U 1 1 5FB68677
P 4625 2425
F 0 "#PWR0101" H 4625 2275 50  0001 C CNN
F 1 "+5V" H 4640 2598 50  0000 C CNN
F 2 "" H 4625 2425 50  0001 C CNN
F 3 "" H 4625 2425 50  0001 C CNN
	1    4625 2425
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5FB68A4B
P 4625 4075
F 0 "#PWR0102" H 4625 3825 50  0001 C CNN
F 1 "GND" H 4630 3902 50  0000 C CNN
F 2 "" H 4625 4075 50  0001 C CNN
F 3 "" H 4625 4075 50  0001 C CNN
	1    4625 4075
	1    0    0    -1  
$EndComp
$Sheet
S 4200 1150 2075 725 
U 5FB69A7B
F0 "3.3v-dc-dc" 50
F1 "3.3v-dc-dc-drop.sch" 50
$EndSheet
$Sheet
S 6525 1150 1650 650 
U 5FB6ABAE
F0 "ESP12F" 50
F1 "esp8266-esp-12f.sch" 50
F2 "GPIO14" I R 8175 1325 50 
F3 "ESPTX" I R 8175 1425 50 
F4 "ESPRX" I R 8175 1525 50 
F5 "GPIO13" I R 8175 1625 50 
F6 "GPIO12" I R 8175 1725 50 
$EndSheet
$Comp
L custom-symbols:Relay_THT_HF49FD R1
U 1 1 5FB69AE9
P 4375 2875
F 0 "R1" H 4525 3025 50  0001 C CNN
F 1 "Relay_THT_HF49FD" V 4375 3403 50  0000 L CNN
F 2 "custom-footprints:Relay_THT_HF49FD" H 4375 2875 50  0001 C CNN
F 3 "" H 4375 2875 50  0001 C CNN
	1    4375 2875
	0    1    1    0   
$EndComp
$Comp
L Transistor_BJT:DTC124E Q1
U 1 1 5FB6E977
P 4525 3675
F 0 "Q1" H 4713 3721 50  0000 L CNN
F 1 "DTC124E" H 4713 3630 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SC-59_Handsoldering" H 4525 3675 50  0001 L CNN
F 3 "" H 4525 3675 50  0001 L CNN
	1    4525 3675
	1    0    0    -1  
$EndComp
Wire Wire Line
	4625 3075 4625 3350
$Comp
L Device:D_Schottky D1
U 1 1 5FB72B45
P 3975 2875
F 0 "D1" V 3929 2955 50  0000 L CNN
F 1 "D_Schottky" V 4020 2955 50  0000 L CNN
F 2 "Diode_SMD:D_SMA_Handsoldering" H 3975 2875 50  0001 C CNN
F 3 "~" H 3975 2875 50  0001 C CNN
	1    3975 2875
	0    1    1    0   
$EndComp
Wire Wire Line
	4625 3350 3975 3350
Wire Wire Line
	3975 3350 3975 3025
Connection ~ 4625 3350
Wire Wire Line
	4625 3350 4625 3475
Wire Wire Line
	3975 2725 3975 2550
Wire Wire Line
	3975 2550 4625 2550
Wire Wire Line
	4625 2550 4625 2675
Wire Wire Line
	4625 2425 4625 2550
Connection ~ 4625 2550
Wire Wire Line
	4775 2675 6100 2675
Text Label 6100 2675 0    50   ~ 0
OUT1
Wire Wire Line
	4775 3075 6100 3075
Text Label 6100 3075 0    50   ~ 0
OUT2
Wire Wire Line
	4625 3875 4625 4075
Wire Wire Line
	4275 3675 3625 3675
Text Label 3625 3675 0    50   ~ 0
RELAY
Text Label 8475 1325 0    50   ~ 0
RELAY
Wire Wire Line
	8475 1325 8175 1325
Text Label 8475 1425 0    50   ~ 0
RX
Text Label 8475 1525 0    50   ~ 0
TX
Text Label 8475 1625 0    50   ~ 0
BTN
Wire Wire Line
	8475 1425 8175 1425
Wire Wire Line
	8475 1525 8175 1525
Wire Wire Line
	8475 1625 8175 1625
Text Label 8475 1725 0    50   ~ 0
STATUS
Wire Wire Line
	8475 1725 8175 1725
$Comp
L Switch:SW_Push SW1
U 1 1 5FB82A2C
P 7150 2775
F 0 "SW1" H 7150 3060 50  0000 C CNN
F 1 "SW_Push" H 7150 2969 50  0000 C CNN
F 2 "custom-footprints:KEY-TH_K2-1102AQ-K4CW-01" H 7150 2975 50  0001 C CNN
F 3 "~" H 7150 2975 50  0001 C CNN
	1    7150 2775
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0115
U 1 1 5FB83982
P 7825 2350
F 0 "#PWR0115" H 7825 2200 50  0001 C CNN
F 1 "+3.3V" H 7840 2523 50  0000 C CNN
F 2 "" H 7825 2350 50  0001 C CNN
F 3 "" H 7825 2350 50  0001 C CNN
	1    7825 2350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0116
U 1 1 5FB83B98
P 7825 3100
F 0 "#PWR0116" H 7825 2850 50  0001 C CNN
F 1 "GND" H 7830 2927 50  0000 C CNN
F 2 "" H 7825 3100 50  0001 C CNN
F 3 "" H 7825 3100 50  0001 C CNN
	1    7825 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6950 2775 6750 2775
Wire Wire Line
	6750 2775 6750 2375
Wire Wire Line
	6750 2375 7825 2375
Wire Wire Line
	7825 2375 7825 2350
Text Label 8500 2750 0    50   ~ 0
BTN
$Comp
L Device:R_Small R3
U 1 1 5FB86A8E
P 8150 2750
F 0 "R3" V 7954 2750 50  0000 C CNN
F 1 "10K" V 8045 2750 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" H 8150 2750 50  0001 C CNN
F 3 "~" H 8150 2750 50  0001 C CNN
	1    8150 2750
	0    1    1    0   
$EndComp
Wire Wire Line
	8500 2750 8350 2750
Wire Wire Line
	8050 2750 7825 2750
Wire Wire Line
	7825 2750 7825 2975
$Comp
L Device:R_Small R2
U 1 1 5FB87912
P 7575 2775
F 0 "R2" V 7379 2775 50  0000 C CNN
F 1 "100" V 7470 2775 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" H 7575 2775 50  0001 C CNN
F 3 "~" H 7575 2775 50  0001 C CNN
	1    7575 2775
	0    1    1    0   
$EndComp
Wire Wire Line
	7350 2775 7475 2775
Wire Wire Line
	7675 2775 7775 2775
Wire Wire Line
	7775 2775 7775 2500
Wire Wire Line
	7775 2500 8350 2500
Wire Wire Line
	8350 2500 8350 2750
Connection ~ 8350 2750
Wire Wire Line
	8350 2750 8250 2750
$Comp
L Device:LED D2
U 1 1 5FB8901C
P 7825 3700
F 0 "D2" H 7818 3917 50  0000 C CNN
F 1 "LED" H 7818 3826 50  0000 C CNN
F 2 "Diode_SMD:D_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 7825 3700 50  0001 C CNN
F 3 "~" H 7825 3700 50  0001 C CNN
	1    7825 3700
	1    0    0    -1  
$EndComp
Text Label 8275 3700 0    50   ~ 0
STATUS
Wire Wire Line
	8275 3700 7975 3700
Wire Wire Line
	7675 3700 7575 3700
Wire Wire Line
	7575 3700 7575 2975
Wire Wire Line
	7575 2975 7825 2975
Connection ~ 7825 2975
Wire Wire Line
	7825 2975 7825 3100
$EndSCHEMATC

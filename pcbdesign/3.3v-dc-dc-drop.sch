EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 3
Title "12V to 3.3v DC-DC"
Date "2020-10-22"
Rev "0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	3700 2700 4200 2700
$Comp
L Device:CP1_Small C1
U 1 1 5F921999
P 4200 2800
F 0 "C1" H 4291 2846 50  0000 L CNN
F 1 "10uF" H 4291 2755 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 4200 2800 50  0001 C CNN
F 3 "~" H 4200 2800 50  0001 C CNN
	1    4200 2800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5F922405
P 4200 2900
F 0 "#PWR0103" H 4200 2650 50  0001 C CNN
F 1 "GND" H 4205 2727 50  0000 C CNN
F 2 "" H 4200 2900 50  0001 C CNN
F 3 "" H 4200 2900 50  0001 C CNN
	1    4200 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 2700 4350 2700
Connection ~ 4200 2700
$Comp
L Regulator_Linear:LM1117-3.3 U1
U 1 1 5F922EEB
P 4850 2700
F 0 "U1" H 4850 2942 50  0000 C CNN
F 1 "LM1117-3.3" H 4850 2851 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-89-3_Handsoldering" H 4850 2700 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm1117.pdf" H 4850 2700 50  0001 C CNN
	1    4850 2700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5F92A08B
P 4850 3200
F 0 "#PWR0104" H 4850 2950 50  0001 C CNN
F 1 "GND" H 4855 3027 50  0000 C CNN
F 2 "" H 4850 3200 50  0001 C CNN
F 3 "" H 4850 3200 50  0001 C CNN
	1    4850 3200
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0105
U 1 1 5F92A96D
P 5650 2700
F 0 "#PWR0105" H 5650 2550 50  0001 C CNN
F 1 "+3.3V" H 5665 2873 50  0000 C CNN
F 2 "" H 5650 2700 50  0001 C CNN
F 3 "" H 5650 2700 50  0001 C CNN
	1    5650 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 2700 5300 2700
$Comp
L Device:CP1_Small C2
U 1 1 5F92B425
P 5650 3000
F 0 "C2" H 5741 3046 50  0000 L CNN
F 1 "100uF" H 5741 2955 50  0000 L CNN
F 2 "Capacitor_SMD:C_Elec_8x10.2" H 5650 3000 50  0001 C CNN
F 3 "~" H 5650 3000 50  0001 C CNN
	1    5650 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 2700 5650 2900
Connection ~ 5650 2700
$Comp
L power:GND #PWR0106
U 1 1 5F92C028
P 5650 3150
F 0 "#PWR0106" H 5650 2900 50  0001 C CNN
F 1 "GND" H 5655 2977 50  0000 C CNN
F 2 "" H 5650 3150 50  0001 C CNN
F 3 "" H 5650 3150 50  0001 C CNN
	1    5650 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 3100 5650 3150
$Comp
L Device:D_Schottky VRD1
U 1 1 5F92D52D
P 4850 2150
F 0 "VRD1" H 4850 2367 50  0000 C CNN
F 1 "D_Schottky" H 4850 2276 50  0000 C CNN
F 2 "Diode_SMD:D_SMA_Handsoldering" H 4850 2150 50  0001 C CNN
F 3 "~" H 4850 2150 50  0001 C CNN
	1    4850 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 2700 5300 2150
Wire Wire Line
	5300 2150 5000 2150
Connection ~ 5300 2700
Wire Wire Line
	5300 2700 5650 2700
Wire Wire Line
	4700 2150 4350 2150
Wire Wire Line
	4350 2150 4350 2700
Connection ~ 4350 2700
Wire Wire Line
	4350 2700 4550 2700
Wire Wire Line
	4850 3000 4850 3200
$Comp
L power:+5V #PWR0107
U 1 1 5FB69E87
P 3700 2700
F 0 "#PWR0107" H 3700 2550 50  0001 C CNN
F 1 "+5V" H 3715 2873 50  0000 C CNN
F 2 "" H 3700 2700 50  0001 C CNN
F 3 "" H 3700 2700 50  0001 C CNN
	1    3700 2700
	1    0    0    -1  
$EndComp
$EndSCHEMATC

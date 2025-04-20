# battery-canister-36c
Design of a battery cannister for diving purposes



# Mechanical

# Electrical
The main components of the electrical system consist of two printed circuit boards (PCBs) and the batteries. The first PCB (BMS Stage) is integrated into the battery pack and is used to monitor, protect and balance the pack. The second PCB (MCU & Buck Stage) steps down the battery pack voltage to a constant output voltage and monitors and controls the switches and output.

## Batteries
A total of 36 batteries in a 6p6s arrangement 



## BMS Stage

![image](https://github.com/user-attachments/assets/dd29fb37-7613-4e50-9edf-47205302bb6b)

## MCU & Buck Stage
The MCU & Buck Stage is a pcb containing a Texas Instruments (TI) LM5146 synchronous buck DC/DC converter to step down the battery voltage to a constant value
![image](https://github.com/user-attachments/assets/25ae875c-627e-42ab-8d7f-50811e8e76fe)


### Performance of Buck Converter

# Software


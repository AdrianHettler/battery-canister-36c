# battery-canister-36c
Design of a battery cannister for diving purposes



# Mechanical

# Electrical
The main components of the electrical system consist of two printed circuit boards (PCBs) and the batteries. The first PCB (BMS Stage) is integrated into the battery pack and is used to monitor, protect and balance the pack. The second PCB (MCU & Buck Stage) steps down the battery pack voltage to a constant output voltage and monitors and controls the switches and output.

## Batteries
A total of 36 batteries in a 6p6s arrangement 



## BMS Stage

![image](https://github.com/user-attachments/assets/42586dd4-7698-4513-bb58-d2e5bb588dc5)


## MCU & Buck Stage
The MCU & Buck Stage is a pcb containing a Texas Instruments (TI) LM5146 synchronous buck DC/DC converter to step down the battery voltage to a constant value
![image](https://github.com/user-attachments/assets/885c1812-9ddb-4c33-a522-844a1277b3f2)



### Performance of Buck Converter

# Software


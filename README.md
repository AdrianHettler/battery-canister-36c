# Design of a Battery Cannister for Diving Purposes

> [!CAUTION]
> Improper use of Li-ion batteries, including short circuits or mishandling, can pose serious risks, potentially resulting in fires or explosions.

# Design Guidelines and Requirements




# Mechanical
![image](https://github.com/user-attachments/assets/6fa03b53-8e0f-4009-9a9b-ca2c3394c98d)




# Electrical
The main components of the electrical system consist of two printed circuit boards (PCBs) and the batteries. The first PCB (BMS Stage) is integrated into the battery pack and is used to monitor, protect and balance the pack. The second PCB (MCU & Buck Stage) steps down the battery pack voltage to a constant output voltage and monitors and controls the switches and output. The PCBs were designed in KiCad, hand assembled and reflow soldered in a modified toaster oven.

## Batteries
A total of 36 Sanyo NCR18650GS Li-ion batteries in a 6p6s arrangement are used. The pack provides a nominal voltage of 21.6V, a charge capacity of 20.7Ah and a energy capacity of 447.12Wh. The battery voltage is not a fixed value and depends on the state of charge of the cell. Hence, the pack voltage ranges from a minimum of 15V to a maximum of 25.2V. The single batteries are spot welded together with 0.2 x 6mm nickel strips. Three NTC therminstors are integrated into the pack to provide temperature readings to the BMS stage.

## BMS Stage
A Texas Instruments (TI) BQ40Z80 battery pack manager is used as primary protection for the battery pack. It has a full array of protection features (voltage, current, temperature, charge timeout, charge & discharge fets, AFE), uses gas gauging to determine and display the exact state of charge and is able to balance cells while charging or at rest. A TI BQ77207 battery protector serves as secondary protection in the event of failure of the primary system. The BQ77207 protects against over- and undervoltage and open-wire faults. A 30A SCF fuse (ITV9550) protects against over-current and short circuits. A resistive heating element inside of the fuse can be used to externally trigger the fuse in cause of a fault that requires permanent disabling of the battery pack. The BMS is designed to handle up to six cells in series.


<p align="center" width="100%">
    <img width="80%" src="https://i.imgur.com/9nHfqQv.png"> 
</p>

Utilizing the EV2400 interface adapter and TI's Battery Management Studio (bqStudio) software, the BQ40Z80 IC can be programmed. After configuring the IC according to the used hardware, a learning cycle that determines the resistance and the total chemical capacity of the battery, needs to be performed.

## MCU & Buck Stage
A TI LM5146 synchronous buck DC/DC converter is used to step down the battery voltage to a constant value. A STM32L031 microcontroller is used for following tasks: 
* Check state of switch / button
* Switching of MOSFETs
* Monitoring of temperature of the pcb
* Monitoring of input voltage and stepped down output voltage
* Control of buzzer
* Enabling & disabling of buck converter
<p align="center" width="100%">
    <img width="80%" src="https://i.imgur.com/jrjpIgM.png"> 
</p>

Due to the fact that the step down converter uses ~1-3W while idling without load, it is very important to be able to switch the buck converter off. This is done by connecting the second channel of the toggle switch in series with the converter's enable pin. If the switch is accidently put in the on-state, a different protection is used. The battery pack voltage drops when a load is applied. A monitoring routine is therefore implemented that sporadically switches the power MOSFETs on and off and checks the battery pack voltages in these states. If a substential drop-of is detected, it is concluded that an acutal load is connected. Otherwise the buck convertes is disabled by pulling the enable pin to ground with the help of a N-channel MOSFET. The pcb can support dual input / output.


### Performance of Buck Converter

Due to conduction, switching and inductor losses, the buck converter does not run at 100% efficiency. The diagramms below show the efficiency and power losses at different input voltages (battery voltage) and under different loads. 



<p align="center" width="100%">
    <img width="80%" src="https://i.imgur.com/pkEGXq9.png"> 
</p>

<p align="center" width="100%">
    <img width="80%" src="https://i.imgur.com/s4CqrV6.png"> 
</p>




# Assembly

## Bill of Materials

# Testing

# Lessons Learned





# Design of a Battery Cannister for Diving Purposes

> [!CAUTION]
> Improper use of Li-ion batteries, including short circuits or mishandling, can pose serious risks, potentially resulting in fires or explosions.

# Mechanical
![image](https://github.com/user-attachments/assets/6fa03b53-8e0f-4009-9a9b-ca2c3394c98d)




# Electrical
The main components of the electrical system consist of two printed circuit boards (PCBs) and the batteries. The first PCB (BMS Stage) is integrated into the battery pack and is used to monitor, protect and balance the pack. The second PCB (MCU & Buck Stage) steps down the battery pack voltage to a constant output voltage and monitors and controls the switches and output. The PCBs were designed in KiCad, hand assembled and reflow soldered in a modified toaster oven.

## Batteries
A total of 36 Sanyo NCR18650GS Li-ion batteries in a 6p6s arrangement are used. The pack provides a nominal voltage of 21.6V, a charge capacity of 20.7Ah and a energy capacity of 447.12Wh. The battery voltage is not a fixed value and depends on the state of charge of the cell. Hence, the pack voltage ranges from a minimum of 15V to a maximum of 25.2V. The single batteries are spot welded together with 0.2 x 6mm nickel strips. Three NTC therminstors are integrated into the pack to provide temperature readings to the BMS stage.

## BMS Stage
A Texas Instruments (TI) BQ40Z80 battery pack manager is used as primary protection for the battery pack. It has a full array of protection features (voltage, current, temperature, charge timeout, charge & discharge fets, AFE), uses gas gauging to determine and display the exact state of charge and is able to balance cells while charging or at rest. A TI BQ77207 battery protector serves as secondary protection in the event of failure of the primary system. The BQ77207 protects against over- and undervoltage and open-wire faults. A 30A SCF fuse (ITV9550) protects against over-current and short circuits. A resistive heating element inside of the fuse can be used to externally trigger the fuse in cause of a fault that requires permanent disabling of the battery pack.

![image](https://github.com/user-attachments/assets/42586dd4-7698-4513-bb58-d2e5bb588dc5)

Utilizing the EV2400 interface adapter and TI's Battery Management Studio (bqStudio) software, the BQ40Z80 IC can be programmed. After configuring the IC according to the used hardware, a learning cycle that determines the resistance and the total chemical capacity of the battery, needs to be performed.

## MCU & Buck Stage
A TI LM5146 synchronous buck DC/DC converter is used to step down the battery voltage to a constant value. A STM32L031 microcontroller is used for following tasks: 
* Check state of switch / button
* Switching of MOSFETs
* Monitoring of temperature of the pcb
* Monitoring of input voltage and stepped down output voltage
* Control of buzzer
* Enabling & disabling of buck converter

![image](https://github.com/user-attachments/assets/885c1812-9ddb-4c33-a522-844a1277b3f2)

Due to the fact that the step down converter uses ~3W while idling without load, it is very important to be able to switch the buck converter off. This is done by connecting the second channel of the toggle switch in series with the converter's enable pin. If the switch is accidently put in the on-state, a different protection is used. The battery pack voltage drops when a load is applied. A monitoring routine is therefore implemented that sporadically switches the power MOSFETs on and off and checks the battery pack voltages in these states. If a substential drop-of is detected, it is concluded that an acutal load is connected. Otherwise the buck convertes is disabled by pulling the enable pin to ground with the help of a N-channel MOSFET.


### Performance of Buck Converter

![losses](https://github.com/user-attachments/assets/41904463-c622-4e61-9609-398ab2e769a8)<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1//EN" "http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd">
<svg width="160mm" height="90mm" viewBox="0 0 16000 9000" version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" stroke-width="28.222" stroke-linejoin="round" xml:space="preserve">
 <path fill="rgb(255,255,255)" stroke="none" d="M 7990,8993 L -13,8993 -13,-13 15992,-13 15992,8993 7990,8993 Z "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 8619,6402 L 1760,6402 1760,1461 15479,1461 15479,6402 8619,6402 Z "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 1760,1460 L 1760,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 3007,1460 L 3007,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 4254,1460 L 4254,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 5501,1460 L 5501,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 6749,1460 L 6749,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 7995,1460 L 7995,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 9242,1460 L 9242,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 10489,1460 L 10489,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 11737,1460 L 11737,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 12984,1460 L 12984,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 14231,1460 L 14231,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 15479,1460 L 15479,6401 "/>
 <path fill="none" stroke="rgb(221,221,221)" stroke-linejoin="round" d="M 2383,1460 L 2383,6401 "/>
 <path fill="none" stroke="rgb(221,221,221)" stroke-linejoin="round" d="M 3630,1460 L 3630,6401 "/>
 <path fill="none" stroke="rgb(221,221,221)" stroke-linejoin="round" d="M 4878,1460 L 4878,6401 "/>
 <path fill="none" stroke="rgb(221,221,221)" stroke-linejoin="round" d="M 6125,1460 L 6125,6401 "/>
 <path fill="none" stroke="rgb(221,221,221)" stroke-linejoin="round" d="M 7372,1460 L 7372,6401 "/>
 <path fill="none" stroke="rgb(221,221,221)" stroke-linejoin="round" d="M 8619,1460 L 8619,6401 "/>
 <path fill="none" stroke="rgb(221,221,221)" stroke-linejoin="round" d="M 9866,1460 L 9866,6401 "/>
 <path fill="none" stroke="rgb(221,221,221)" stroke-linejoin="round" d="M 11113,1460 L 11113,6401 "/>
 <path fill="none" stroke="rgb(221,221,221)" stroke-linejoin="round" d="M 12360,1460 L 12360,6401 "/>
 <path fill="none" stroke="rgb(221,221,221)" stroke-linejoin="round" d="M 13608,1460 L 13608,6401 "/>
 <path fill="none" stroke="rgb(221,221,221)" stroke-linejoin="round" d="M 14855,1460 L 14855,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 15479,6401 L 1760,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 15479,5695 L 1760,5695 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 15479,4989 L 1760,4989 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 15479,4284 L 1760,4284 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 15479,3578 L 1760,3578 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 15479,2872 L 1760,2872 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 15479,2166 L 1760,2166 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 15479,1460 L 1760,1460 "/>
 <path fill="none" stroke="rgb(221,221,221)" stroke-linejoin="round" d="M 15479,6048 L 1760,6048 "/>
 <path fill="none" stroke="rgb(221,221,221)" stroke-linejoin="round" d="M 15479,5342 L 1760,5342 "/>
 <path fill="none" stroke="rgb(221,221,221)" stroke-linejoin="round" d="M 15479,4636 L 1760,4636 "/>
 <path fill="none" stroke="rgb(221,221,221)" stroke-linejoin="round" d="M 15479,3931 L 1760,3931 "/>
 <path fill="none" stroke="rgb(221,221,221)" stroke-linejoin="round" d="M 15479,3225 L 1760,3225 "/>
 <path fill="none" stroke="rgb(221,221,221)" stroke-linejoin="round" d="M 15479,2519 L 1760,2519 "/>
 <path fill="none" stroke="rgb(221,221,221)" stroke-linejoin="round" d="M 15479,1813 L 1760,1813 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 1760,6551 L 1760,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 1760,6551 L 1760,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 3007,6551 L 3007,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 3007,6551 L 3007,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 4254,6551 L 4254,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 4254,6551 L 4254,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 5501,6551 L 5501,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 5501,6551 L 5501,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 6749,6551 L 6749,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 6749,6551 L 6749,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 7995,6551 L 7995,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 7995,6551 L 7995,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 9242,6551 L 9242,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 9242,6551 L 9242,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 10489,6551 L 10489,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 10489,6551 L 10489,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 11737,6551 L 11737,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 11737,6551 L 11737,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 12984,6551 L 12984,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 12984,6551 L 12984,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 14231,6551 L 14231,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 14231,6551 L 14231,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 15479,6551 L 15479,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 15479,6551 L 15479,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 1760,6401 L 15479,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 1610,6401 L 1760,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 1610,6401 L 1760,6401 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 1610,5695 L 1760,5695 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 1610,5695 L 1760,5695 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 1610,4989 L 1760,4989 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 1610,4989 L 1760,4989 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 1610,4284 L 1760,4284 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 1610,4284 L 1760,4284 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 1610,3578 L 1760,3578 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 1610,3578 L 1760,3578 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 1610,2872 L 1760,2872 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 1610,2872 L 1760,2872 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 1610,2166 L 1760,2166 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 1610,2166 L 1760,2166 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 1610,1460 L 1760,1460 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 1610,1460 L 1760,1460 "/>
 <path fill="none" stroke="rgb(179,179,179)" stroke-linejoin="round" d="M 1760,6401 L 1760,1460 "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-width="53" stroke-linejoin="round" d="M 1760,5829 L 3007,5711 4254,5560 5501,5409 6749,5247 7995,5087 9242,4918 10489,4723 11737,4533 12984,4334 14231,4125 15479,3887 "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 1685,5754 L 1685,5904 1835,5904 1835,5754 1685,5754 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 1685,5754 L 1685,5904 1835,5904 1835,5754 1685,5754 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 2932,5636 L 2932,5786 3082,5786 3082,5636 2932,5636 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 2932,5636 L 2932,5786 3082,5786 3082,5636 2932,5636 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 4179,5485 L 4179,5635 4329,5635 4329,5485 4179,5485 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 4179,5485 L 4179,5635 4329,5635 4329,5485 4179,5485 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 5426,5334 L 5426,5484 5576,5484 5576,5334 5426,5334 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 5426,5334 L 5426,5484 5576,5484 5576,5334 5426,5334 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 6674,5172 L 6674,5322 6824,5322 6824,5172 6674,5172 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 6674,5172 L 6674,5322 6824,5322 6824,5172 6674,5172 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 7921,5012 L 7921,5162 8070,5162 8070,5012 7921,5012 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 7921,5012 L 7921,5162 8070,5162 8070,5012 7921,5012 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 9167,4843 L 9167,4993 9317,4993 9317,4843 9167,4843 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 9167,4843 L 9167,4993 9317,4993 9317,4843 9167,4843 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 10414,4648 L 10414,4798 10564,4798 10564,4648 10414,4648 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 10414,4648 L 10414,4798 10564,4798 10564,4648 10414,4648 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 11662,4459 L 11662,4608 11812,4608 11812,4459 11662,4459 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 11662,4459 L 11662,4608 11812,4608 11812,4459 11662,4459 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 12909,4259 L 12909,4409 13059,4409 13059,4259 12909,4259 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 12909,4259 L 12909,4409 13059,4409 13059,4259 12909,4259 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 14156,4050 L 14156,4200 14306,4200 14306,4050 14156,4050 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 14156,4050 L 14156,4200 14306,4200 14306,4050 14156,4050 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 15404,3812 L 15404,3962 15554,3962 15554,3812 15404,3812 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 15404,3812 L 15404,3962 15554,3962 15554,3812 15404,3812 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-width="53" stroke-linejoin="round" d="M 1760,5599 L 3007,5524 4254,5296 5501,5144 6749,5013 7995,4953 9242,4583 10489,4413 11737,4280 12984,4022 14231,3754 15479,3465 "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 1685,5599 L 1760,5674 1835,5599 1760,5524 1685,5599 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 1685,5599 L 1760,5674 1835,5599 1760,5524 1685,5599 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 2932,5524 L 3007,5599 3082,5524 3007,5449 2932,5524 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 2932,5524 L 3007,5599 3082,5524 3007,5449 2932,5524 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 4179,5296 L 4254,5371 4329,5296 4254,5221 4179,5296 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 4179,5296 L 4254,5371 4329,5296 4254,5221 4179,5296 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 5426,5144 L 5501,5219 5576,5144 5501,5069 5426,5144 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 5426,5144 L 5501,5219 5576,5144 5501,5069 5426,5144 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 6674,5013 L 6749,5088 6824,5013 6749,4938 6674,5013 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 6674,5013 L 6749,5088 6824,5013 6749,4938 6674,5013 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 7921,4953 L 7995,5028 8070,4953 7995,4878 7921,4953 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 7921,4953 L 7995,5028 8070,4953 7995,4878 7921,4953 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 9167,4583 L 9242,4658 9317,4583 9242,4508 9167,4583 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 9167,4583 L 9242,4658 9317,4583 9242,4508 9167,4583 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 10414,4413 L 10489,4488 10564,4413 10489,4338 10414,4413 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 10414,4413 L 10489,4488 10564,4413 10489,4338 10414,4413 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 11662,4280 L 11737,4355 11812,4280 11737,4205 11662,4280 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 11662,4280 L 11737,4355 11812,4280 11737,4205 11662,4280 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 12909,4022 L 12984,4097 13059,4022 12984,3947 12909,4022 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 12909,4022 L 12984,4097 13059,4022 12984,3947 12909,4022 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 14156,3754 L 14231,3829 14306,3754 14231,3679 14156,3754 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 14156,3754 L 14231,3829 14306,3754 14231,3679 14156,3754 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 15404,3465 L 15479,3540 15554,3465 15479,3390 15404,3465 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 15404,3465 L 15479,3540 15554,3465 15479,3390 15404,3465 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-width="53" stroke-linejoin="round" d="M 1760,5112 L 3007,5087 4254,4720 5501,4593 6749,4439 7995,4213 9242,3948 10489,3768 11737,3581 12984,3281 14231,3013 15479,2674 "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 1685,5037 L 1760,5187 1835,5037 1685,5037 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 1685,5037 L 1760,5187 1835,5037 1685,5037 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 2932,5012 L 3007,5162 3082,5012 2932,5012 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 2932,5012 L 3007,5162 3082,5012 2932,5012 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 4179,4645 L 4254,4795 4329,4645 4179,4645 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 4179,4645 L 4254,4795 4329,4645 4179,4645 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 5426,4518 L 5501,4668 5576,4518 5426,4518 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 5426,4518 L 5501,4668 5576,4518 5426,4518 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 6674,4364 L 6749,4513 6824,4364 6674,4364 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 6674,4364 L 6749,4513 6824,4364 6674,4364 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 7921,4138 L 7995,4288 8070,4138 7921,4138 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 7921,4138 L 7995,4288 8070,4138 7921,4138 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 9167,3873 L 9242,4023 9317,3873 9167,3873 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 9167,3873 L 9242,4023 9317,3873 9167,3873 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 10414,3693 L 10489,3843 10564,3693 10414,3693 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 10414,3693 L 10489,3843 10564,3693 10414,3693 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 11662,3506 L 11737,3656 11812,3506 11662,3506 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 11662,3506 L 11737,3656 11812,3506 11662,3506 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 12909,3206 L 12984,3356 13059,3206 12909,3206 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 12909,3206 L 12984,3356 13059,3206 12909,3206 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 14156,2938 L 14231,3088 14306,2938 14156,2938 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 14156,2938 L 14231,3088 14306,2938 14156,2938 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 15404,2599 L 15479,2749 15554,2599 15404,2599 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 15404,2599 L 15479,2749 15554,2599 15404,2599 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-width="53" stroke-linejoin="round" d="M 1760,4354 L 3007,4312 4254,4185 5501,4036 6749,3705 7995,3719 9242,3401 10489,3578 11737,3295 12984,2617 14231,2519 15479,2123 "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 1685,4429 L 1835,4429 1760,4279 1685,4429 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 1685,4429 L 1835,4429 1760,4279 1685,4429 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 2932,4387 L 3082,4387 3007,4237 2932,4387 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 2932,4387 L 3082,4387 3007,4237 2932,4387 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 4179,4260 L 4329,4260 4254,4110 4179,4260 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 4179,4260 L 4329,4260 4254,4110 4179,4260 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 5426,4111 L 5576,4111 5501,3961 5426,4111 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 5426,4111 L 5576,4111 5501,3961 5426,4111 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 6674,3780 L 6824,3780 6749,3630 6674,3780 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 6674,3780 L 6824,3780 6749,3630 6674,3780 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 7921,3794 L 8070,3794 7995,3644 7921,3794 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 7921,3794 L 8070,3794 7995,3644 7921,3794 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 9167,3476 L 9317,3476 9242,3326 9167,3476 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 9167,3476 L 9317,3476 9242,3326 9167,3476 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 10414,3653 L 10564,3653 10489,3503 10414,3653 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 10414,3653 L 10564,3653 10489,3503 10414,3653 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 11662,3370 L 11812,3370 11737,3220 11662,3370 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 11662,3370 L 11812,3370 11737,3220 11662,3370 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 12909,2692 L 13059,2692 12984,2542 12909,2692 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 12909,2692 L 13059,2692 12984,2542 12909,2692 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 14156,2594 L 14306,2594 14231,2444 14156,2594 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 14156,2594 L 14306,2594 14231,2444 14156,2594 Z "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 15404,2198 L 15554,2198 15479,2048 15404,2198 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 15404,2198 L 15554,2198 15479,2048 15404,2198 Z "/>
 <text class="SVGTextShape"><tspan class="TextParagraph"><tspan class="TextPosition" x="1569" y="6969"><tspan font-family="Liberation Sans, sans-serif" font-size="353px" font-weight="400" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">15</tspan></tspan></tspan></text>
 <text class="SVGTextShape"><tspan class="TextParagraph"><tspan class="TextPosition" x="2816" y="6969"><tspan font-family="Liberation Sans, sans-serif" font-size="353px" font-weight="400" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">16</tspan></tspan></tspan></text>
 <text class="SVGTextShape"><tspan class="TextParagraph"><tspan class="TextPosition" x="4063" y="6969"><tspan font-family="Liberation Sans, sans-serif" font-size="353px" font-weight="400" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">17</tspan></tspan></tspan></text>
 <text class="SVGTextShape"><tspan class="TextParagraph"><tspan class="TextPosition" x="5310" y="6969"><tspan font-family="Liberation Sans, sans-serif" font-size="353px" font-weight="400" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">18</tspan></tspan></tspan></text>
 <text class="SVGTextShape"><tspan class="TextParagraph"><tspan class="TextPosition" x="6558" y="6969"><tspan font-family="Liberation Sans, sans-serif" font-size="353px" font-weight="400" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">19</tspan></tspan></tspan></text>
 <text class="SVGTextShape"><tspan class="TextParagraph"><tspan class="TextPosition" x="7805" y="6969"><tspan font-family="Liberation Sans, sans-serif" font-size="353px" font-weight="400" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">20</tspan></tspan></tspan></text>
 <text class="SVGTextShape"><tspan class="TextParagraph"><tspan class="TextPosition" x="9051" y="6969"><tspan font-family="Liberation Sans, sans-serif" font-size="353px" font-weight="400" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">21</tspan></tspan></tspan></text>
 <text class="SVGTextShape"><tspan class="TextParagraph"><tspan class="TextPosition" x="10298" y="6969"><tspan font-family="Liberation Sans, sans-serif" font-size="353px" font-weight="400" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">22</tspan></tspan></tspan></text>
 <text class="SVGTextShape"><tspan class="TextParagraph"><tspan class="TextPosition" x="11546" y="6969"><tspan font-family="Liberation Sans, sans-serif" font-size="353px" font-weight="400" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">23</tspan></tspan></tspan></text>
 <text class="SVGTextShape"><tspan class="TextParagraph"><tspan class="TextPosition" x="12793" y="6969"><tspan font-family="Liberation Sans, sans-serif" font-size="353px" font-weight="400" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">24</tspan></tspan></tspan></text>
 <text class="SVGTextShape"><tspan class="TextParagraph"><tspan class="TextPosition" x="14040" y="6969"><tspan font-family="Liberation Sans, sans-serif" font-size="353px" font-weight="400" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">25</tspan></tspan></tspan></text>
 <text class="SVGTextShape"><tspan class="TextParagraph"><tspan class="TextPosition" x="15288" y="6969"><tspan font-family="Liberation Sans, sans-serif" font-size="353px" font-weight="400" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">26</tspan></tspan></tspan></text>
 <text class="SVGTextShape"><tspan class="TextParagraph"><tspan class="TextPosition" x="1319" y="6522"><tspan font-family="Liberation Sans, sans-serif" font-size="353px" font-weight="400" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">0</tspan></tspan></tspan></text>
 <text class="SVGTextShape"><tspan class="TextParagraph"><tspan class="TextPosition" x="1319" y="5816"><tspan font-family="Liberation Sans, sans-serif" font-size="353px" font-weight="400" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">1</tspan></tspan></tspan></text>
 <text class="SVGTextShape"><tspan class="TextParagraph"><tspan class="TextPosition" x="1319" y="5110"><tspan font-family="Liberation Sans, sans-serif" font-size="353px" font-weight="400" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">2</tspan></tspan></tspan></text>
 <text class="SVGTextShape"><tspan class="TextParagraph"><tspan class="TextPosition" x="1319" y="4405"><tspan font-family="Liberation Sans, sans-serif" font-size="353px" font-weight="400" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">3</tspan></tspan></tspan></text>
 <text class="SVGTextShape"><tspan class="TextParagraph"><tspan class="TextPosition" x="1319" y="3699"><tspan font-family="Liberation Sans, sans-serif" font-size="353px" font-weight="400" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">4</tspan></tspan></tspan></text>
 <text class="SVGTextShape"><tspan class="TextParagraph"><tspan class="TextPosition" x="1319" y="2993"><tspan font-family="Liberation Sans, sans-serif" font-size="353px" font-weight="400" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">5</tspan></tspan></tspan></text>
 <text class="SVGTextShape"><tspan class="TextParagraph"><tspan class="TextPosition" x="1319" y="2287"><tspan font-family="Liberation Sans, sans-serif" font-size="353px" font-weight="400" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">6</tspan></tspan></tspan></text>
 <text class="SVGTextShape"><tspan class="TextParagraph"><tspan class="TextPosition" x="1319" y="1581"><tspan font-family="Liberation Sans, sans-serif" font-size="353px" font-weight="400" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">7</tspan></tspan></tspan></text>
 <text class="SVGTextShape"><tspan class="TextParagraph"><tspan class="TextPosition" x="6153" y="839"><tspan font-family="Liberation Sans, sans-serif" font-size="459px" font-weight="700" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">Electrical Losses</tspan></tspan></tspan></text>
 <path fill="none" stroke="rgb(0,0,0)" stroke-width="53" stroke-linejoin="round" d="M 3649,8692 L 4449,8692 "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 3943,8587 L 3943,8798 4154,8798 4154,8587 3943,8587 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 3943,8587 L 3943,8798 4154,8798 4154,8587 3943,8587 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-width="53" stroke-linejoin="round" d="M 6083,8692 L 6883,8692 "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 6377,8692 L 6483,8798 6588,8692 6483,8587 6377,8692 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 6377,8692 L 6483,8798 6588,8692 6483,8587 6377,8692 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-width="53" stroke-linejoin="round" d="M 8401,8692 L 9201,8692 "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 8695,8587 L 8801,8798 8906,8587 8695,8587 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 8695,8587 L 8801,8798 8906,8587 8695,8587 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-width="53" stroke-linejoin="round" d="M 10529,8692 L 11329,8692 "/>
 <path fill="rgb(0,0,0)" stroke="none" d="M 10823,8798 L 11034,8798 10929,8587 10823,8798 Z "/>
 <path fill="none" stroke="rgb(0,0,0)" stroke-linejoin="round" d="M 10823,8798 L 11034,8798 10929,8587 10823,8798 Z "/>
 <text class="SVGTextShape"><tspan class="TextParagraph"><tspan class="TextPosition" x="4549" y="8812"><tspan font-family="Liberation Sans, sans-serif" font-size="353px" font-weight="400" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">No Load</tspan></tspan></tspan></text>
 <text class="SVGTextShape"><tspan class="TextParagraph"><tspan class="TextPosition" x="6983" y="8812"><tspan font-family="Liberation Sans, sans-serif" font-size="353px" font-weight="400" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">35.75W</tspan></tspan></tspan></text>
 <text class="SVGTextShape"><tspan class="TextParagraph"><tspan class="TextPosition" x="9301" y="8812"><tspan font-family="Liberation Sans, sans-serif" font-size="353px" font-weight="400" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">52.5W</tspan></tspan></tspan></text>
 <text class="SVGTextShape"><tspan class="TextParagraph"><tspan class="TextPosition" x="11429" y="8812"><tspan font-family="Liberation Sans, sans-serif" font-size="353px" font-weight="400" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">106W</tspan></tspan></tspan></text>
 <text class="SVGTextShape"><tspan class="TextParagraph"><tspan class="TextPosition" x="7278" y="7616"><tspan font-family="Liberation Sans, sans-serif" font-size="318px" font-weight="400" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">Input Voltage [W]</tspan></tspan></tspan></text>
 <text class="SVGTextShape" transform="rotate(-90 825 4949)"><tspan class="TextParagraph"><tspan class="TextPosition" x="825" y="4949"><tspan font-family="Liberation Sans, sans-serif" font-size="318px" font-weight="400" fill="rgb(0,0,0)" stroke="none" style="white-space: pre">Losses [W}</tspan></tspan></tspan></text>
</svg>



# Assembly

## Bill of Materials

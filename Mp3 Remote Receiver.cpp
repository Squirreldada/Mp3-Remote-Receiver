//加载Arduino内置库
#include <Arduino.h>
#include <pins_arduino.h>
#include <HardwareSerial.h>
#include <wiring_private.h>
#include <binary.h>
#include <Client.h>
#include <IPAddress.h>
#include <new.h>
#include <Platform.h>
#include <Printable.h>
#include <Print.h>
#include <Server.h>
#include <Stream.h>
#include <Udp.h>
#include <USBAPI.h>
#include <USBCore.h>
#include <USBDesc.h>
#include <WCharacter.h>
#include <WString.h>
//加载遥控模块库
#include <RCSwitch.h>

RCSwitch Receiver = RCSwitch(); //定义接收端

void setup() {
	Receiver.enableReceive(0); //接收端接中断0（中断0为Arduino的2口，中断1为Arduino的3口）
	pinMode(2, INPUT);
	pinMode(3, OUTPUT); //PP Mode
	pinMode(4, OUTPUT); //Next V++
	pinMode(5, OUTPUT); //Prev V--
	pinMode(6, OUTPUT); //EQ
	pinMode(7, OUTPUT); //Repeat
	pinMode(8, OUTPUT); //REC
}

void loop() {
	if (Receiver.available()) {
		int value = Receiver.getReceivedValue(); //接收端获取数据
		if (value != 0) {
			if (value == 1) {
				//PP
				digitalWrite(3, HIGH);
				delay(200);
				digitalWrite(3, LOW);
			}
			if (value == 2) {
				//Mode
				digitalWrite(3, HIGH);
				delay(1500);
				digitalWrite(3, LOW);
			}
			if (value == 3) {
				//Next
				digitalWrite(4, HIGH);
				delay(200);
				digitalWrite(4, LOW);
			}
			if (value == 4) {
				//Prev
				digitalWrite(5, HIGH);
				delay(200);
				digitalWrite(5, LOW);
			}
			if (value == 5) {
				//V++
				digitalWrite(4, HIGH);
				delay(1000);
				digitalWrite(4, LOW);
			}
			if (value == 6) {
				//V--
				digitalWrite(5, HIGH);
				delay(1000);
				digitalWrite(5, LOW);
			}
			if (value == 7) {
				//EQ
				digitalWrite(6, HIGH);
				delay(200);
				digitalWrite(6, LOW);
			}
			if (value == 8) {
				//Repeat
				digitalWrite(7, HIGH);
				delay(200);
				digitalWrite(7, LOW);
			}
			if (value == 9) {
				//REC
				digitalWrite(8, HIGH);
				delay(200);
				digitalWrite(8, LOW);
			}
		}
		Receiver.resetAvailable(); //接收端重设活动状态。估计上次接收后，就把该状态改了，所以这里要重新设置。
	}
	//delay(1000);
}

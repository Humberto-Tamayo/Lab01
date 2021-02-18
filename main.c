//++++++LIBRARIEs/HEADERs SECTION++++++
#include "config.h"
//++++++DIRECTIVEs SECTION+++++++++++++
#define _XTAL_FREQ 1000000
#define ONE_SECOND 1000

//++++++++++DATA TYPEs SECTION+++++++++++++
//Enumeration is a user defined data type in C. It is mainly used to assign
//names to integral constants, the names makes a program easy to read and 
//maintain. 

enum por_dir{ output, input };           //output = 0, input = 1
enum por_ACDC{ digital, analog };        //digital = 0 , analog = 1
enum resistor_state{ set_ON, res_ON };   //set_ON = 0, res_ON = 1
enum led_state{ led_OFF, led_ON };       //let_OFF = 0, let_ON = 1
enum butto_state{ pushed, no_pushed };   //pushed = 0, no_pushed = 1

//+++++++++++IRSs SECTION++++++++++++++++++++
//ISR for high-priority
void __interrupt ( high_priority ) high_isr( void );
//ISR for low priority 
void __interrupt ( low_priority ) low_isr( void );

//++++++++++++FUNCTIONS DECLARATION+++++++++++++++++++++
void portsInit( void );             //Ports Configuration 

//++++++++++++MAIN SECTION++++++++++++++++++++++++++++++
void main( void ) {
    //CONFIGURATIONS******************************
    portsInit();        //Ports Configuration
    //INFINITE CYCLE************************************
    while( 1 ) {
        if( PORTBbits.RB4 == pushed ) //If a button is pushed then:
            LATAbits.LATA7 = led_OFF; //Turn on the RA4 LED.
        else                          //Otherwise   
            LATAbits.LATA7 = led_ON;  //Turn off the RA4 LED.
        LATAbits.LATA7 = led_ON;       //Turn on RA4 LED.
        __delay_ms( ONE_SECOND );     //delay function XC8 compiler.
        LATAbits.LATA7 = led_OFF;     //Turn off RA4 LED.
        __delay_ms( ONE_SECOND );     //delay function XC8 compiler.
    }
}

//++++++++++++++FUNCTIONs SECTION+++++++++++++++++++
void portsInit( void ) {                //Ports Configuration
    ANSELA = digital;                   //Set PortA as digital port.
    TRISAbits.TRISA4 = output;          //Set RA4 as output.
    TRISAbits.TRISA7 = output;          //Set RA7 as output.
    ANSELB = digital;                   //Set PortB as digital port.
    TRISBbits.TRISB4 = input;           //Set RB4 as input.
}
//++++++++++++++++++++END+++++++++++++++++++++++++++++
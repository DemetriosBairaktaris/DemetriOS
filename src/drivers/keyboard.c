
#include <terminal.h>
#include "ports.h"
/*#include "queue"*/
 int shift = 0 ;
 uint8_t oldcode = -1 ; 
unsigned char keymap[58] =
{
    /*Scan Code Set 1.*/
    0,0,'1','2',
    '3','4','5','6',
    '7','8','9','0',
     '-','=',0,0,
    'q','w','e','r',
    't','y','u','i',
    'o','p','[',']',
    '\n','^','a','s','d',
    'f','g','h','j',
    'k','l',';','\'','`','!','@',
    'z','x', 'c','v',
    'b','n', 'm',',','.',
    '/',0,0,0,' '
};
unsigned char keymapshifted[58] =
{
    /*Scan Code Set 1.*/
    0,0,'!','@',
    '#','$','%','^',
    '&','*','(',')',
     '_','+',0,0,
    'Q','W','E','R',
    'T','Y','U','I',
    'O','P','{','}',
    '\n','^','A','S','D',
    'F','G','H','J',
    'K','L',':','\"','~','0','0',
    'Z','X', 'C','V',
    'B','N', 'M','<','>',
    '?',0,0,0,' '
};


 void keyboard_handler(uint8_t code){   
    if (oldcode == code){return ;}
    unsigned char scancode;
    scancode = code ; 
    
    if (code & 0x80)
    {
        shift = 0 ;
        oldcode = -1 ; 
    }
    else
    {
        if(scancode == 90){
            terminal_writestring("\n");
        }
        else if(scancode == 0x0E){
            terminal_backspace();
        }
        else if(scancode == 0xE0){
            terminal_writestring(scancode);
        }
        else if (scancode == 0x2A){shift = 1;}
        
        else{
            char q;
            if (shift){q = keymapshifted[scancode];}
            else{ q = keymap[scancode];}
            terminal_putchar(q);
        }
        oldcode = code ; 
    }
}

void keyboard_initialize(){

    while (1){
        uint8_t x ;
        x = inb(0x60);
        keyboard_handler(x);
    } 
}

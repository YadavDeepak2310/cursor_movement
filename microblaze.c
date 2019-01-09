#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xiomodule.h"


int main()
{
	init_platform();

	 char pos;
	 char switches;
	 signed int loc = 0x00A7;
	 u16 xmask = 0x1F0;
	 u16 ymask = 0x00F;
	 signed int xloc;
	 signed int yloc;

	 XIOModule gpi;
	 XIOModule gpo;

	 switches = XIOModule_Initialize(&gpi, XPAR_IOMODULE_0_DEVICE_ID);
	 switches = XIOModule_Start(&gpi);

	 XIOModule_Initialize(&gpo, XPAR_IOMODULE_0_DEVICE_ID);
	 XIOModule_Start(&gpo);

	 xil_printf("DEEPAK YADAV\n\r");
	 xil_printf("Date : 11/14/2018\n\r");
	 xil_printf("loc ix %x\n\r",loc);
	 while(1)

	 {
	 xil_printf("Choose color of the box by using switches 3-0\n\r");
	 switches = XIOModule_DiscreteRead(&gpi, 1);		//read switches
	 //xil_printf("switches pressed %c",switches);
     switch (switches) {
     	 case 1 : XIOModule_DiscreteWrite ( &gpo, 1, 0x00F);
     	 	 	  xil_printf("Box Color is RED\n\r");
     	 	 break;
     	 case 2 : XIOModule_DiscreteWrite ( &gpo, 1, 0x0F0);
 	 	          xil_printf("Box Color is GREEN\n\r");
     	 	 break;
     	 case 3 : XIOModule_DiscreteWrite ( &gpo, 1, 0x0FF);
 	 	          xil_printf("Box Color is YELLOW\n\r");
     	     break;
     	 case 4 : XIOModule_DiscreteWrite ( &gpo, 1, 0xF00);
 	 	          xil_printf("Box Color is BLUE\n\r");
     	     break;
     	 case 5 : XIOModule_DiscreteWrite ( &gpo, 1, 0xFFF);
 	 	          xil_printf("Box Color is WHITE\n\r");
     	     break;
     	 default :XIOModule_DiscreteWrite ( &gpo, 1, 0x000);
     	          xil_printf("Box Color is BLACK, so it's Invisible\n\r");
     		 break;
     	 	 	  }

     pos = inbyte();

     xloc = (loc & xmask)>>4;
     yloc = loc & ymask;


     if (((xloc-0x1) > -1) && ((xloc+0x1 )<20) && ((yloc-0x1) >-1) && ((yloc+0x1) <15)){
     switch (pos) {
          	 case 'w' : loc = loc - 0x001;
          		 	  XIOModule_DiscreteWrite ( &gpo, 2, loc);
          	 	 	  xil_printf("Box is at [%d:%d] \n\r",xloc,yloc);
          	 	 break;
          	 case 'W' : loc = loc - 0x001;
          		 	  XIOModule_DiscreteWrite ( &gpo, 2, loc);
          	 	 	  xil_printf("Box is at [%d:%d] \n\r",xloc,yloc);
          	 	 break;
          	 case 'a' : loc = loc - 0x010;
          		 	  XIOModule_DiscreteWrite ( &gpo, 2, loc);
          	 	 	  xil_printf("Box is at [%d:%d] \n\r",xloc,yloc);
          	 	 break;
          	 case 'A' : loc = loc - 0x010;
          		 	  XIOModule_DiscreteWrite ( &gpo, 2, loc);
          	 	 	  xil_printf("Box is at [%d:%d] \n\r",xloc,yloc);
          	 	 break;
          	 case 's' : loc = loc + 0x001;
          		 	  XIOModule_DiscreteWrite ( &gpo, 2, loc);
          	 	 	  xil_printf("Box is at [%d:%d] \n\r",xloc,yloc);
          	 	 break;
          	 case 'S' : loc = loc + 0x001;
          		 	  XIOModule_DiscreteWrite ( &gpo, 2, loc);
          	 	 	  xil_printf("Box is at [%d:%d] \n\r",xloc,yloc);
          	 	 break;
          	 case 'd' : loc = loc + 0x010;
          		 	  XIOModule_DiscreteWrite ( &gpo, 2, loc);
          	 	 	  xil_printf("Box is at [%d:%d] \n\r",xloc,yloc);
          	 	 break;
          	 case 'D' : loc = loc + 0x010;
          		 	  XIOModule_DiscreteWrite ( &gpo, 2, loc);
          	 	 	  xil_printf("Box is at [%d:%d] \n\r",xloc,yloc);
          	 	 break;
          	 default :XIOModule_DiscreteWrite ( &gpo, 2, loc);
          	          xil_printf("Box Color is BLACK, so it's Invisible\n\r");
          		 break;
          	 	 	  }
     }else if(xloc == 0){
    	 loc = loc + 0x010;
     }else if(xloc == 19){
    	 loc = loc - 0x010;
	 }else if(yloc == 14){
		 loc = loc - 0x001;
	 }else if(yloc == 0){
		 loc = loc + 0x001;
	 }else
	 {
		 xil_printf("You've reached Edge, reverse direction\n\r");
	 }
	 }
	 cleanup_platform();
	 return 0;
}

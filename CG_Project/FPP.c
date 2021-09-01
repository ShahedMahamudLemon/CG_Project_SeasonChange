#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

int rund(double x) { return ((int)(x*10))%10>5?(int)++x:(int)x; }

void axes(){

	glColor3f (1.0, 0.0, 0.0);

	glBegin(GL_POINTS);

	for(int i=-1000;i<=1000;i++){
		glVertex2d(0,i);
		glVertex2d(i,0);
	}

	glEnd();
}

void rectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){

	glColor3f (1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	glVertex2d(x1,y1);
	glVertex2d(x2,y2);
	glVertex2d(x3,y3);
	glVertex2d(x4,y4);

	glEnd();
}

void rectangleColor(double c1, double c2, double c3, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){

	glColor3f (c1, c2, c3);

	glBegin(GL_POLYGON);

	glVertex2d(x1,y1);
	glVertex2d(x2,y2);
	glVertex2d(x3,y3);
	glVertex2d(x4,y4);

	glEnd();
}

void midPointFill(double c1, double c2, double c3, int xc, int yc, int r){

	glColor3f (c1,c2,c3);

	int x0=0, y0=r, p0=1-r;
	int ax0[1111], ay0[1111];
	int idx0=0;
	ax0[idx0]=x0;
	ay0[idx0++]=y0;
	while(1){
		if(p0<0){
			x0++; p0=p0+(2*x0)+1;
		}
		else{
			x0++; y0--; p0=p0+(2*x0)+1-2*y0;
		}
		ax0[idx0]=x0; ay0[idx0++]=y0;
		if(x0>=y0) break;
	}

	glBegin(GL_POLYGON);
	int tx0,ty0;
	for(int i=0;i<idx0;i++){
		tx0=ax0[i]*(-1); ty0=ay0[i]*(-1);
		glVertex2d(ax0[i]+xc,ay0[i]+yc);
		glVertex2d(tx0+xc,ay0[i]+yc);
		glVertex2d(ax0[i]+xc,ty0+yc);
		glVertex2d(tx0+xc,ty0+yc);
		glVertex2d(ay0[i]+xc,ax0[i]+yc);
		glVertex2d(ty0+xc,ax0[i]+yc);
		glVertex2d(ay0[i]+xc,tx0+yc);
		glVertex2d(ty0+xc,tx0+yc);
	}
	glEnd();
}

void midPointBlank(double c1, double c2, double c3, int xc, int yc, int r){

	glColor3f (c1,c2,c3);

	int x0=0, y0=r, p0=1-r;
	int ax0[1111], ay0[1111];
	int idx0=0;
	ax0[idx0]=x0;
	ay0[idx0++]=y0;
	while(1){
		if(p0<0){
			x0++; p0=p0+(2*x0)+1;
		}
		else{
			x0++; y0--; p0=p0+(2*x0)+1-2*y0;
		}
		ax0[idx0]=x0; ay0[idx0++]=y0;
		if(x0>=y0) break;
	}

	glBegin(GL_POINTS);
	int tx0,ty0;
	for(int i=0;i<idx0;i++){
		tx0=ax0[i]*(-1); ty0=ay0[i]*(-1);
		glVertex2d(ax0[i]+xc,ay0[i]+yc);
		glVertex2d(tx0+xc,ay0[i]+yc);
		glVertex2d(ax0[i]+xc,ty0+yc);
		glVertex2d(tx0+xc,ty0+yc);
		glVertex2d(ay0[i]+xc,ax0[i]+yc);
		glVertex2d(ty0+xc,ax0[i]+yc);
		glVertex2d(ay0[i]+xc,tx0+yc);
		glVertex2d(ty0+xc,tx0+yc);
	}
	glEnd();
}

void midPointBlank2(double c1, double c2, double c3, int xc, int yc, int r){

	glColor3f (c1,c2,c3);

	int x0=0, y0=r, p0=1-r;
	int ax0[1111], ay0[1111];
	int idx0=0;
	ax0[idx0]=x0;
	ay0[idx0++]=y0;
	while(1){
		if(p0<0){
			x0++; p0=p0+(2*x0)+1;
		}
		else{
			x0++; y0--; p0=p0+(2*x0)+1-2*y0;
		}
		ax0[idx0]=x0; ay0[idx0++]=y0;
		if(x0>=y0) break;
	}

	glBegin(GL_POINTS);
	int tx0,ty0;
	for(int i=0;i<idx0;i++){
		tx0=ax0[i]*(-1); ty0=ay0[i]*(-1);
		if(ax0[i]+xc>=-660 && ax0[i]+xc<=660) glVertex2d(ax0[i]+xc,ay0[i]+yc);
		if(tx0+xc>=-660 && tx0+xc<=660) glVertex2d(tx0+xc,ay0[i]+yc);
		if(ax0[i]+xc>=-660 && ax0[i]+xc<=660) glVertex2d(ax0[i]+xc,ty0+yc);
		if(tx0+xc>=-660 && tx0+xc<=660) glVertex2d(tx0+xc,ty0+yc);
		if(ay0[i]+xc>=-660 && ay0[i]+xc<=660) glVertex2d(ay0[i]+xc,ax0[i]+yc);
		if(ty0+xc>=-660 && ty0+xc<=660) glVertex2d(ty0+xc,ax0[i]+yc);
		if(ay0[i]+xc>=-660 && ay0[i]+xc<=660) glVertex2d(ay0[i]+xc,tx0+yc);
		if(ty0+xc>=-660 && ty0+xc<=660) glVertex2d(ty0+xc,tx0+yc);
	}
	glEnd();
}

void midPointFill2(double c1, double c2, double c3, int xc, int yc, int r, int limit){

	glColor3f (c1,c2,c3);

	int x0=0, y0=r, p0=1-r;
	int ax0[1111], ay0[1111];
	int idx0=0;
	ax0[idx0]=x0;
	ay0[idx0++]=y0;
	while(1){
		if(p0<0){
			x0++; p0=p0+(2*x0)+1;
		}
		else{
			x0++; y0--; p0=p0+(2*x0)+1-2*y0;
		}
		ax0[idx0]=x0; ay0[idx0++]=y0;
		if(x0>=y0) break;
	}

	glBegin(GL_POLYGON);
	int tx0,ty0;
	for(int i=0;i<idx0;i++){
		tx0=ax0[i]*(-1); ty0=ay0[i]*(-1);
		if(ay0[i]+yc>=limit) glVertex2d(ax0[i]+xc,ay0[i]+yc);
		if(ay0[i]+yc>=limit) glVertex2d(tx0+xc,ay0[i]+yc);
		if(ty0+yc>=limit) glVertex2d(ax0[i]+xc,ty0+yc);
		if(ty0+yc>=limit) glVertex2d(tx0+xc,ty0+yc);
		if(ax0[i]+yc>=limit) glVertex2d(ay0[i]+xc,ax0[i]+yc);
		if(ax0[i]+yc>=limit) glVertex2d(ty0+xc,ax0[i]+yc);
		if(tx0+yc>=limit) glVertex2d(ay0[i]+xc,tx0+yc);
		if(tx0+yc>=limit) glVertex2d(ty0+xc,tx0+yc);
	}
	glEnd();
}

void window0(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){

	rectangleColor(0.42,0.28,0.20, x1+39,y1+5, x2-37,y2+5, x2-37,y2+25, x1+39,y1+25);	// top box
	rectangleColor(0.92,0.78,0.63, x1,y1, x2,y2, x3,y3, x4,y4);							// outer frame
	rectangleColor(0.42,0.28,0.20, x1-5,y1, x2+5,y2, x2+5,y2-5, x1-5,y1-5);				// shade
	rectangleColor(0.33,0.22,0.16, x1+5,y1-10, x2-66,y2-10, x3-66,y3+8, x4+5,y4+8);		// left box
	rectangleColor(0.33,0.22,0.16, x1+68,y1-10, x2-5,y2-10, x3-5,y3+8, x4+68,y4+8);		// right box

}

void window1(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){

	rectangleColor(0.42,0.28,0.20, x1+25,y1+4, x2-25,y2+4, x2-25,y2+16, x1+25,y1+16);	// top box
	rectangleColor(0.92,0.78,0.63, x1,y1, x2,y2, x3,y3, x4,y4);							// outer frame
	rectangleColor(0.42,0.28,0.20, x1-4,y1+1, x2+4,y2+1, x2+4,y2-4, x1-4,y1-4);			// shade
	rectangleColor(0.33,0.22,0.16, x1+4,y1-8, x2-38,y2-8, x3-38,y3+5, x4+4,y4+5);		// left box
	rectangleColor(0.33,0.22,0.16, x1+38,y1-8, x2-4,y2-8, x3-4,y3+5, x4+38,y4+5);		// right box
}

void window2(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){

	rectangleColor(0.42,0.28,0.20, x1+25,y1+5, x2-25,y2+5, x2-25,y2+20, x1+25,y1+20);	// top box
	rectangleColor(0.92,0.78,0.63, x1,y1, x2,y2, x3,y3, x4,y4);							// outer frame
	rectangleColor(0.42,0.28,0.20, x1-5,y1, x2+5,y2, x2+5,y2-5, x1-5,y1-5);			// shade
	rectangleColor(0.33,0.22,0.16, x1+5,y1-10, x2-49,y2-10, x3-49,y3+8, x4+5,y4+8);		// left box
	rectangleColor(0.33,0.22,0.16, x1+49,y1-10, x2-5,y2-10, x3-5,y3+8, x4+49,y4+8);		// right box
}

void window3(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){

	rectangleColor(0.42,0.28,0.20, x1+55,y1+10, x2-55,y2+10, x2-55,y2+40, x1+55,y1+40);	// top box
	rectangleColor(0.92,0.78,0.63, x1,y1, x2,y2, x3,y3, x4,y4);							// outer frame
	rectangleColor(0.42,0.28,0.20, x1-10,y1, x2+10,y2, x2+10,y2-10, x1-10,y1-10);				// shade
	rectangleColor(0.33,0.22,0.16, x1+10,y1-20, x2-100,y2-20, x3-100,y3+10, x4+10,y4+10);		// left box
	rectangleColor(0.33,0.22,0.16, x1+100,y1-20, x2-10,y2-20, x3-10,y3+10, x4+100,y4+10);		// right box
}

void wall_gate(){

	// prachir
	rectangleColor(0.38,0.27,0.18, -31,-790, 255,-790, 255,-960, -31,-960);
	rectangleColor(0.38,0.27,0.18, 393,-790, 660,-790, 660,-960, 393,-960);

	// gate
	rectangleColor(0.38,0.27,0.18, 235,-750, 255,-750, 255,-960, 235,-960);
	rectangleColor(0.38,0.27,0.18, 393,-750, 413,-750, 413,-960, 393,-960);
	rectangleColor(0.38,0.27,0.18, 235,-740, 413,-740, 413,-750, 235,-750);
	rectangleColor(0.38,0.27,0.18, 235,-850, 413,-850, 413,-860, 235,-860);
	rectangleColor(0.38,0.27,0.18, 265,-750, 270,-750, 270,-960, 265,-960);
	rectangleColor(0.38,0.27,0.18, 383,-750, 378,-750, 378,-960, 383,-960);
	rectangleColor(0.38,0.27,0.18, 280,-750, 285,-750, 285,-960, 280,-960);
	rectangleColor(0.38,0.27,0.18, 368,-750, 363,-750, 363,-960, 368,-960);
	rectangleColor(0.38,0.27,0.18, 295,-750, 302,-750, 302,-960, 295,-960);
	rectangleColor(0.38,0.27,0.18, 353,-750, 348,-750, 348,-960, 353,-960);
	rectangleColor(0.38,0.27,0.18, 312,-750, 317,-750, 317,-960, 312,-960);
	rectangleColor(0.38,0.27,0.18, 336,-750, 331,-750, 331,-960, 336,-960);

}

void bicycle(){

	// back wheel outer circle 1
	for(int i=61;i<=70;i++) midPointBlank(0.17,0.13,0.13, -560,-890, i);

	// back wheel outer circle 2
	for(int i=56;i<=60;i++) midPointBlank(0.29,0.23,0.23, -560,-890, i);

	// back wheel center circle
	midPointFill(0.29,0.23,0.23, -560,-890, 15);

	// front wheel outer circle 1
	for(int i=61;i<=70;i++) midPointBlank(0.17,0.13,0.13, -293,-890, i);

	// front wheel outer circle 2
	for(int i=56;i<=60;i++) midPointBlank(0.29,0.23,0.23, -293,-890, i);

	// front wheel center circle
	midPointFill(0.29,0.23,0.23, -293,-890, 15);

	// lower padel verti line
	rectangleColor(0.29,0.23,0.23, -430,-890, -424,-890, -424,-930, -430,-930);

	// lower padel horiz line
	rectangleColor(0.29,0.23,0.23, -434,-930, -418,-930, -418,-935, -434,-935);

	// center wheel outer circle 1
	for(int i=22;i<=25;i++) midPointBlank(0.17,0.13,0.13, -427,-890, i);

	// center wheel center circle
	midPointFill(0.17,0.13,0.13, -427,-890, 14);

	// center-back center line
	rectangleColor(0.17,0.13,0.13, -560,-893, -427,-893, -427,-887, -560,-887);

	// upper chain line
	rectangleColor(0.17,0.13,0.13, -560,-875, -427,-865, -427,-860, -560,-880);

	// upper chain line
	rectangleColor(0.17,0.13,0.13, -560,-905, -427,-915, -427,-920, -560,-900);

	// back wheel center circle
	midPointFill(0.29,0.23,0.23, -560,-890, 15);

	// upper padel verti line -427,-890
	rectangleColor(0.29,0.23,0.23, -430,-890, -424,-890, -424,-850, -430,-850);

	// upper padel horiz line
	rectangleColor(0.29,0.23,0.23, -434,-850, -418,-850, -418,-855, -434,-855);

	// back line
	rectangleColor(0.17,0.13,0.13, -565,-890, -555,-890, -505,-790, -515,-790);

	// back-center line
	rectangleColor(0.17,0.13,0.13, -432,-890, -422,-890, -505,-790, -515,-790);

	// front line
	rectangleColor(0.17,0.13,0.13, -288,-890, -298,-890, -338,-790, -328,-790);

	// front-center line
	rectangleColor(0.17,0.13,0.13, -422,-890, -432,-890, -338,-790, -328,-790);

	// upper line
	rectangleColor(0.17,0.13,0.13, -515,-780, -515,-790, -328,-790, -328,-780);

	// seat verti line
	rectangleColor(0.17,0.13,0.13, -515,-780, -505,-780, -510,-760, -520,-760);

	// seat horiz line
	rectangleColor(0.17,0.13,0.13, -530,-760, -500,-760, -500,-755, -530,-755);

	// handle verti line
	rectangleColor(0.17,0.13,0.13, -338,-780, -328,-780, -333,-760, -343,-760);

	// handle horiz line
	rectangleColor(0.17,0.13,0.13, -363,-760, -323,-760, -323,-755, -363,-755);
	rectangleColor(0.17,0.13,0.13, -323,-755, -333,-755, -353,-745, -343,-745);;

}

void cloud(int x, int y){

	// border
	midPointFill2(0.33,0.22,0.16, -420+x, 800+y, 65, 735+y);
	midPointFill2(0.33,0.22,0.16, -360+x, 810+y, 80, 735+y);
	midPointFill2(0.33,0.22,0.16, -280+x, 820+y, 105, 735+y);
	midPointFill2(0.33,0.22,0.16, -190+x, 805+y, 70, 735+y);
	rectangleColor(0.33,0.22,0.16, -420+x,735+y, -190+x,735+y, -190+x,800+y, -420+x,800+y);

	midPointFill2(1.0,1.0,1.0, -420+x, 800+y, 60, 740+y);
	midPointFill2(1.0,1.0,1.0, -360+x, 810+y, 75, 740+y);
	midPointFill2(1.0,1.0,1.0, -280+x, 820+y, 100, 740+y);
	midPointFill2(1.0,1.0,1.0, -190+x, 805+y, 65, 740+y);
	rectangleColor(1.0,1.0,1.0, -420+x,740+y, -190+x,740+y, -190+x,800+y, -420+x,800+y);

}

void buildings(){

	// building0
	int b_border=10;
	rectangleColor(0.64,0.44,0.27, -660,700, -660,-960, -237,-960, -237,700);
	rectangleColor(0.82,0.61,0.41, -660+b_border,700-b_border, -660+b_border,-960, -237-b_border,-960, -237-b_border,700-b_border); 	//inner building

	// divider0
	rectangleColor(0.42,0.28,0.20, -660,167, -227,167, -227,137, -660,137);
	rectangleColor(0.42,0.28,0.20, -660,-396, -227,-396, -227,-426, -660,-426);

	// upper0 part
	// window0 left-top
	window0(-620,610, -490,610, -490,459, -620,459);
	// window0 right-top
	window0(-407,610, -277,610, -277,459, -407,459);
	// window0 left-bottom
	window0(-620,377, -490,377, -490,226, -620,226);
	// window0 right-bottom
	window0(-407,377, -277,377, -277,226, -407,226);

	// middle0 part
	// window0 left-top
	window0(-620,57, -490,57, -490,-95, -620,-95);
	// window0 right-top
	window0(-407,57, -277,57, -277,-95, -407,-95);
	// window0 left-bottom
	window0(-620,-177, -490,-177, -490,-328, -620,-328);
	// window0 right-bottom
	window0(-407,-177, -277,-177, -277,-328, -407,-328);

	// lower0 part
	// window0 left-top
	window0(-620,-506, -490,-506, -490,-657, -620,-657);
	// window0 right-top
	window0(-407,-506, -277,-506, -277,-657, -407,-657);


	// building1
	rectangleColor(0.8,0.66,0.48, -183,25, -96,25, -96,-50, -183,-50);
	rectangleColor(0.64,0.44,0.27, -237,-50, -96,-50, -96,-960, -237,-960);
	rectangleColor(0.82,0.61,0.41, -237,-50-b_border, -96-b_border,-50-b_border, -96-b_border,-960, -237,-960); 	//inner building

	// divider1
	rectangleColor(0.42,0.28,0.20, -237,-343, -86,-343, -86,-358, -237,-358);
	rectangleColor(0.42,0.28,0.20, -237,-651, -86,-651, -86,-666, -237,-666);


	// upper1 part
	// window1 top
	window1(-199,-96, -126,-96, -126,-179, -199,-179);
	// window1 bottom
	window1(-199,-237, -126,-237, -126,-320, -199,-320);

	// middle1 part
	// window1 top
	window1(-199,-394, -126,-394, -126,-477, -199,-477);
	// window1 bottom
	window1(-199,-535, -126,-535, -126,-618, -199,-618);

	// lower1 part
	// window1 top
	window1(-199,-702, -126,-702, -126,-785, -199,-785);


	// building2
	rectangleColor(0.64,0.44,0.27, -66,137, 235,137, 235,-960, -66,-960);
	rectangleColor(0.82,0.61,0.41, -66+b_border,137-b_border, 235-b_border,137-b_border, 235-b_border,-960, -66+b_border,-960); 	//inner building

	//divider2
	rectangleColor(0.42,0.28,0.20, -76,-304, 245,-304, 245,-324, -76,-324);
	rectangleColor(0.42,0.28,0.20, -76,-766, 245,-766, 245,-786, -76,-786);

	// upper2 part
	// window2 left-top
	window2(-31,64, 62,64, 62,-48, -31,-48);
	// window2 right-top
	window2(106,64, 200,64, 200,-48, 106,-48);
	// window2 left-bottom
	window2(-31,-144, 62,-144, 62,-257, -31,-257);
	// window2 right-bottom
	window2(106,-144, 200,-144, 200,-257, 106,-257);

	// middle2 part
	window2(-31,-371, 62,-371, 62,-484, -31,-484);
	// window2 right-top
	window2(106,-371, 200,-371, 200,-484, 106,-484);
	// window2 left-bottom
	window2(-31,-606, 62,-606, 62,-719, -31,-719);
	// window2 right-bottom
	window2(106,-606, 200,-606, 200,-719, 106,-719);


	// building3
	rectangleColor(0.8,0.66,0.48, 490,226, 660,226, 660,7, 490,7);
	rectangleColor(0.64,0.44,0.27, -11,7, 660,7, 660,-960, -11,-960);
	rectangleColor(0.82,0.61,0.41, -11+b_border,7-b_border, 660-b_border,7-b_border, 660-b_border,-960, -11+b_border,-960); 	//inner building

	// window left-top
	window3(58,-112, 248,-112, 248,-332, 58,-332);
	// window right-top
	window3(400,-112, 590,-112, 590,-332, 400,-332);
	// window left-bottom
	window3(58,-640, 248,-640, 248,-860, 58,-860);
	// window right-bottom
	window3(400,-640, 590,-640, 590,-860, 400,-860);
}

void wire_polls(){

	// wire
	for(int i=396;i<=400;i++) midPointBlank2(0.24,0.18,0.18, 0,i,1010);
	for(int i=396;i<=400;i++) midPointBlank2(0.24,0.18,0.18, 20,i,1010);
	for(int i=396;i<=400;i++) midPointBlank2(0.24,0.18,0.18, -100,i,1010);
	for(int i=396;i<=400;i++) midPointBlank2(0.24,0.18,0.18, 100,i,1010);

	// poll
	rectangleColor(0.24,0.18,0.18, -660,-150, -640,-150, -640,-960, -660,-960);
	rectangleColor(0.24,0.18,0.18, -660,-270, -500,-240, -500,-280, -660,-310);
	rectangleColor(0.24,0.18,0.18, -660,-350, -540,-325, -540,-340, -660,-365);
	rectangleColor(0.24,0.18,0.18, -660,-385, -500,-355, -500,-370, -660,-400);
	rectangleColor(0.24,0.18,0.18, -530,-330, -515,-330, -515,-405, -530,-405);

	rectangleColor(0.24,0.18,0.18, -600,-480, -560,-480, -560,-600, -600,-600);
	rectangleColor(0.24,0.18,0.18, -660,-530, -570,-500, -570,-520, -660,-550);
	rectangleColor(0.24,0.18,0.18, -660,-580, -570,-550, -570,-570, -660,-600);

	rectangleColor(0.24,0.18,0.18, 660,-170, 640,-170, 640,-960, 660,-960);
	rectangleColor(0.24,0.18,0.18, 660,-260, 500,-290, 500,-330, 660,-300);
	rectangleColor(0.24,0.18,0.18, 660,-340, 540,-365, 540,-380, 660,-355);
	rectangleColor(0.24,0.18,0.18, 660,-375, 500,-405, 500,-420, 660,-390);
	rectangleColor(0.24,0.18,0.18, 530,-370, 515,-370, 515,-445, 530,-445);

	rectangleColor(0.24,0.18,0.18, 600,-500, 560,-500, 560,-620, 600,-620);
	rectangleColor(0.24,0.18,0.18, 660,-500, 570,-530, 570,-550, 660,-520);
	rectangleColor(0.24,0.18,0.18, 660,-550, 570,-580, 570,-600, 660,-570);
}

void display(void){

	glClear (GL_COLOR_BUFFER_BIT);

	// screen
	rectangle(-700,1000, -700,-1000, 700,-1000, 700,1000);
	// axes();

	// background
	rectangleColor(0.16,0.12,0.06, -700,1000, -700,-1000, 700,-1000, 700,1000);

	// sun
	midPointFill(0.97,0.87,0.70, 70,50, 500);

	buildings();

	wall_gate();

	wire_polls();

	bicycle();

	glFlush();
}

void clouds(void){

	glClear (GL_COLOR_BUFFER_BIT);

	int cx1=-133-1350, cx2=157-1350, cx3=447-1350, cx4=737-1350;
	float inc_fac1=0.0,inc_fac2=0.0,inc_fac3=0.0,inc_fac4=0.0;

	for (float j = 0; j < 1000; j += 0.001){
		glClear (GL_COLOR_BUFFER_BIT);

		// screen
		rectangle(-700,1000, -700,-1000, 700,-1000, 700,1000);
		// axes();

		// background
		rectangleColor(0.16,0.12,0.06, -700,1000, -700,-1000, 700,-1000, 700,1000);

		// sun
		midPointFill(0.97,0.87,0.70, 70,50, 500);

		// clouds
		cloud(cx1+(600 *inc_fac1),-30);
		cloud(cx2+(600 *inc_fac2),-250);
		cloud(cx3+(600 *inc_fac3),-30);
		cloud(cx4+(600 *inc_fac4),-250);

		inc_fac1+=0.002;
		inc_fac2+=0.002;
		inc_fac3+=0.002;
		inc_fac4+=0.002;

		if(cx1+(600 *inc_fac1)>1200){
			inc_fac1=0.0;
			inc_fac2=0.0;
			inc_fac3=0.0;
			inc_fac4=0.0;
		}

		buildings();

		wall_gate();

		wire_polls();

		bicycle();

		glFlush();

	}

}

void cloudsrev(void){

	glClear (GL_COLOR_BUFFER_BIT);

	// initial positions of clouds
	int cx1=-1483, cx2=-1193, cx3=-903, cx4=-613;

	// increasing factor of each move
	float inc_fac=0.0;

	for (;;){
		glClear (GL_COLOR_BUFFER_BIT);

		// screen
		rectangle(-700,1000, -700,-1000, 700,-1000, 700,1000);
		// axes();

		// background
		rectangleColor(0.16,0.12,0.06, -700,1000, -700,-1000, 700,-1000, 700,1000);

		// sun
		midPointFill(0.97,0.87,0.70, 70,50, 500);

		// clouds
		cloud(cx1-(600 *inc_fac),-30);
		cloud(cx2-(600 *inc_fac),-250);
		cloud(cx3-(600 *inc_fac),-30);
		cloud(cx4-(600 *inc_fac),-250);

		inc_fac+=0.002;

		if(cx1+(600 *inc_fac)>1200){ inc_fac=0.0; }

		buildings();

		wall_gate();

		wire_polls();

		bicycle();

		glFlush();

	}

}

void keyboard(unsigned char key, int x, int y)
{
	if(key=='c' || key=='C'){
		clouds();
	}
}

void init (void){

	glClearColor (0.0, 0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-700,700,-1000,1000);		//fix the windows size
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (750, 1000);
	glutInitWindowPosition (50, 50);
	glutCreateWindow ("The City of Clouds");
	init ();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	return 0;
}

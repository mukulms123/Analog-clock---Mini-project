#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<iostream.h>

int calculatehrs(int h)
{
	int x;
	switch(h)
	{
		case 0: x=90;
		break;
		case 1:
		case 13: x=60;
		break;
		case 2:
		case 14: x=30;
		break;
		case 3:
		case 15: x=0;
		break;
		case 4:
		case 16: x=330;
		break;
		case 5:
		case 17: x=300;
		break;
		case 6:
		case 18: x=270;
		break;
		case 7:
		case 19: x=240;
		break;
		case 8:
		case 20: x=210;
		break;
		case 9:
		case 21: x=180;
		break;
		case 10:
		case 22: x=150;
		break;
		case 11:
		case 23: x=120;
		break;
		case 12:
		case 24: x=90;
		break;
	}
	return(x);
}

int calculatemin(int m)
{
	int x;
	if(m%5==0)
	{
		switch(m)
		{
			case 0: x=90;
			break;
			case 5: x=60;
			break;
			case 10: x=30;
			break;
			case 15: x=360;
			break;
			case 20: x=330;
			break;
			case 25: x=300;
			break;
			case 30: x=270;
			break;
			case 35: x=240;
			break;
			case 40: x=210;
			break;
			case 45: x=180;
			break;
			case 50: x=150;
			break;
			case 55: x=120;
			break;
			case 60: x=90;
			break;
		}
	}
	else
	{
		if(m>0&&m<15)
		{
			x= 90-(m*6);
		}

		if(m>15&&m<30)
		{
			x=360-((m-15)*6);
		}

		if(m>30&&m<45)
		{
			x= 270-((m-30)*6);
		}

		if(m>45&&m<60)
		{
			x=180-((m-45)*6);
		}

	}
	return(x);
}

int changehrs(int m,int a)
{
	if(m>15&&m<=30)
	a-=12;
	if(m>30&&m<=45)
	a-=18;
	if(m>45&&m<60)
	a-=24;
	return (a);
}

void main()
{
	int gdriver=DETECT,gmode,h,m,s,a,b,c;
	initgraph(&gdriver,&gmode,"C:/TURBOC3/BGI");
	int h_jap, m_jap, s_jap, h_york, m_york, s_york, h_lon, m_lon, s_lon;

	struct  time t;
	gettime(&t);
	h=t.ti_hour;
	m=t.ti_min;
	s=t.ti_sec;

	h_jap = h + 3;
	if(h_jap>23){
		h_jap = h_jap - 25;
	}
	m_jap = m + 30;
		if(m_jap>59){
		m_jap = m_jap - 60;
		h_jap= h_jap+1;
	}

	s_jap = s;

	h_york = h - 9;
	if(h_york<0){
		h_york = 25 + h_york;
	}
	m_york = m - 30;
		if(m_york< 0){
		m_york = m_york + 60;
		h_york=h_york-1;
	}

	s_york = s;

	h_lon = h - 4;
	if(h_lon<0){
		h_lon = 25 + h_lon;
	}
	m_lon = m - 30;
		if(m_lon< 0){
		m_lon = m_lon + 60;
		h_lon=h_lon-1;
	}

	s_lon = s;


	int a_jap ,b_jap, c_jap, a_york, b_york, c_york, a_lon, b_lon, c_lon;

	a=calculatehrs(h);
	b=calculatemin(m);
	c=calculatemin(s);
	a=changehrs(m,a);

	a_jap=calculatehrs(h_jap);
	b_jap=calculatemin(m_jap);
	c_jap=calculatemin(s_jap);
	a_jap=changehrs(m_jap,a_jap);


	a_york=calculatehrs(h_york);
	b_york=calculatemin(m_york);
	c_york=calculatemin(s_york);
	a_york=changehrs(m_york,a_york);


	a_lon=calculatehrs(h_lon);
	b_lon=calculatemin(m_lon);
	c_lon=calculatemin(s_lon);
	a_lon=changehrs(m_lon,a_lon);


	for(int i=a;i>0;i-=6,a_jap-=6,a_york-=6,a_lon-=6)
		for(int j=b;j>0;j-=6,b_jap-=6,b_york-=6,b_lon-=6)
			for(int k=c;k>0;k-=6,c_jap-=6,c_york-=6,c_lon-=6)
			{
				setbkcolor(WHITE);
				settextstyle(1,HORIZ_DIR,2);
				setcolor(BLUE);
				outtextxy(245,20,"Analog Clock");

				settextstyle(8,HORIZ_DIR,2);


				outtextxy(385,170,"3");
				outtextxy(288,78,"12");
				outtextxy(207,170,"9");
				outtextxy(295,250,"6");

				settextstyle(3,HORIZ_DIR,1);
				setcolor(6);
				circle(300,180,102);
				setcolor(1);
				circle(300,180,100);

				outtextxy(290,290,"India");


				setcolor(6);
				circle(100,380,52);
				setcolor(1);
				circle(100,380,50);
				outtextxy(75,435, "Japan");


				outtextxy(137,370,"3");
				outtextxy(90,327,"12");
				outtextxy(55,370,"9");
				outtextxy(94,408,"6");


				setcolor(6);
				circle(320,380,52);
				setcolor(1);
				circle(320,380,50);
				outtextxy(275,435,"New York");


				outtextxy(357,370,"3");
				outtextxy(310,327,"12");
				outtextxy(275,370,"9");
				outtextxy(314,408,"6");

				setcolor(6);
				circle(520,380,52);
				setcolor(1);
				circle(520,380,50);
				outtextxy(490,435, "London");

					outtextxy(557,370,"3");
					outtextxy(510,327,"12");
					outtextxy(475,370,"9");
					outtextxy(514,408,"6");



				circle(345,103,2);
				circle(378,135,2);
				circle(378,225,2);
				circle(345,260,2);
				circle(253,258,2);
				circle(223,225,2);
				circle(223,135,2);
				circle(253,103,2);

				setcolor(RED);
				pieslice(300,180,i-2,i,75);
				pieslice(100,380,a_jap-1,a_jap,30);
				pieslice(320,380,a_york-1,a_york,30);
				pieslice(520,380,a_lon-1,a_lon,30);


				setcolor(GREEN);
				pieslice(300,180,j-2,j,85);
				pieslice(100,380,b_jap-1,b_jap,40);
				pieslice(320,380,b_york-1,b_york,40);
				pieslice(520,380,b_lon-1,b_lon,40);

				setcolor(BLUE);
				pieslice(300,180,k-1,k,95);
				pieslice(100,380,c_jap-1,c_jap,45);
				pieslice(320,380,c_york-1,c_york,45);
				pieslice(520,380,c_lon-1,c_lon,45) ;

				setcolor(RED);
				settextstyle(3,HORIZ_DIR,1);
				outtextxy(400,50,"Press any key to exit!.");
				sleep(1);
				clearviewport();

				if(i==6)
				a=360;
				if(j==6)
				b=360;
				if(k==6)
				c=360;

				if(kbhit())
				{
					sleep(1);
					exit(0);
				}

				}
}
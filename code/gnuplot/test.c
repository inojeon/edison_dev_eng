#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main()
{
	double x,y;
	int i,imax;
      double phi;
	double pi = 4.*atan(1.);
      double T;//,T_sb;
	double nsb = 5.;
      char command[100];

	FILE *fp_c;
      fp_c = fopen("data.dat","w");
	FILE *fp_p;
	FILE *fp_shot;
	FILE *fp_plot;
      fp_plot = fopen("plot.gnu","w");
	fprintf(fp_plot,"set terminal gif animate delay 4\nset output  'plot.gif'\n unset key\n");
	fprintf(fp_plot,"set size ratio 1\n");
	fprintf(fp_plot,"unset key\n");
      imax = nsb*40;
	int nro = 1;	//number of rotation
	double xp[imax*nro],yp[nro*imax];
	int p;

      T = 2.;
//        T_sb = T/2.;
	int temp;
	int l,m;
	
	p = 0;
	double xpp = -50,ypp = 50;
	for(m=1;m<=nro*imax+imax/10;m++)
	{
		fp_c = fopen("data.dat","w");
		fp_shot = fopen("shot.dat","w");

		for(i=0;i<m;i++)
		{
			phi = 2.*pi/((double) imax)*((double) i);

			x = cos(phi);
			y = sin(phi);
			
       		fprintf(fp_c,"%d %lf %lf	%d\n",i,x,y,0);
			temp = i%(imax/(int)nsb);
			//if(i == imax/nsb)
			if(temp == 0)
			{
       		 	fprintf(fp_c,"%d %lf %lf	%d\n",i,x,y,-1);
       		 	fprintf(fp_c,"%d %lf %lf	%d\n",i,x,y,0);
       		 	fprintf(fp_c,"%d %lf %lf	%d\n",i,x,y,1);
       		 	fprintf(fp_shot,"%d %lf %lf	%d\n",i,x,y,1);
				xp[i] = x;	yp[i] = y;	
			}
			printf("%d\n",m);
		}
		 printf("%d\n",m);

		fclose(fp_c);
		fclose(fp_shot);
		fp_p = fopen("point.dat","w");
		phi = 2.*pi/((double) imax)*((double) m);
		x = cos(phi);
		y = sin(phi);
			
		temp = i%(imax/(int)nsb);
		//if(i == imax/nsb)
		if(temp == 0)
		{
       	 	fprintf(fp_p,"%d %lf %lf	%d\n",m,x,y,1);
		}
		else
       	{
			fprintf(fp_p,"%d %lf %lf	%d\n",m,x,y,0);
		}
		fclose(fp_p);

		sprintf(command,"cp data.dat data%d.dat",m);
		system(command);
		sprintf(command,"cp point.dat point%d.dat",m);
		system(command);
		sprintf(command,"cp shot.dat shot%d.dat",m);
		system(command);

		fprintf(fp_plot,"set multiplot layout 2,1\n");
		fprintf(fp_plot,"set size ratio 1\n");
		fprintf(fp_plot,"set xrange [-1.1:1.1]\n");
		fprintf(fp_plot,"set yrange [-1.1:1.1]\n");
		fprintf(fp_plot,"unset xtics\n");
		fprintf(fp_plot,"unset ytics\n");
		if(temp == 0)
		{
			p = p + 1;
  			fprintf(fp_plot,"set label %d '%d shot' at %lf,%lf font ',12'\n",1,p,x-0.5,y);
			xpp=x-0.5; ypp=y;
		}
		fprintf(fp_plot,"plot 'data%d.dat' u 2:3 w l,'point%d.dat' u 2:3 pt 7,'shot%d.dat' u 2:3 pt 7 ps 1.2\n",m,m,m);

		fprintf(fp_plot,"set yr [-1.1:1.1]\n");
		fprintf(fp_plot,"set xr [0:%d*%d]\n",nro,imax);
		fprintf(fp_plot,"set size ratio 0.4\n");
		fprintf(fp_plot,"unset xtics\n");

		if(temp == 0)
		{
//  		fprintf(fp_plot,"set label %d '%d shot' at %d,%lf\n",p+1,p,m,0.);
		}
//			if(temp == 0)
//			{fprintf(fp_plot,"unset label %d \n",1);}
		fprintf(fp_plot,"unset label %d \n",1);

		fprintf(fp_plot,"plot 'data%d.dat' u 1:3 w l,'data%d.dat' u 1:4 w l lw 2,'point%d.dat' u 1:3 pt 7,'point%d.dat' u 1:4 pt 7,'shot%d.dat' u 1:(0) pt 7 ps 1.2\n",m,m,m,m,m);
			
  		fprintf(fp_plot,"set label %d '%d shot' at %lf,%lf font ',12'\n",1,p,xpp,ypp);
		if(temp == 0)
		{
  			fprintf(fp_plot,"set label %d '%d shot' at %d,%lf\n",p+1,p,m+5,-0.1);
  			fprintf(fp_plot,"set label %d '%d shot' at %lf,%lf font ',12'\n",1,p,x-0.5,y);
		}


		fprintf(fp_plot,"unset multiplot\n");
		printf("%d\n",m);
	}
	system("rm -rf result");
	system("mkdir result");
	system("gnuplot plot.gnu");
//	system("rm -f *.dat");
//	system("rm -f plot.gnu");
	system("mv plot.gif result/");

}


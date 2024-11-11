def generate_M_C(xr,yr,xl,yl):
	global m
	m = float(yr - yl)/float(xr - xl)
	global c
	c = yr - xr*m
	# print ("m = %f, c=%f " %(m,c))

def get_point_on_circle1 (xr,yr,radius):
	# print( (((1.0/m)**2) +1)  )
	y=yr-( (radius**(2 )) / (((1.0/m)**2) +1) )**(0.5)
	x=(1.0/m)*(y-yr)+xr
	return [x,y]

def get_point_on_circle2 (xr,yr,radius):
	# print( (((1.0/m)**2) +1)  )
	y=yr+( (radius**(2 )) / (((1.0/m)**2) +1) )**(0.5)
	x=(1.0/m)*(y-yr)+xr
	return [x,y]

def get_center ( xc,yc,xl,yl ):
	return float(xl+xc)/2 ,float(yl+yc)/2

def get_rad ( xc,yc,xl,yl ):
	rad = (( (xc-xl)**2 + (yc-yl)**2 )**(0.5))/(2.0)
	return rad

def main ():	
	x=input().split()
	R = float(x[0])
	xr = float(x[1])
	yr = float(x[2])
	xl = float(x[3])
	yl = float(x[4])

	if (get_rad(xl,yl,xr,yr)*2 >= R ):
		print(xr,yr,R)

	else:
		if(float(yr - yl) !=0 and float(xr - xl) !=0):	
			generate_M_C(xr,yr,xl,yl)

			XC1,YC1=get_point_on_circle1(xr,yr,R)
			XC2,YC2=get_point_on_circle2(xr,yr,R)

			if get_rad ( XC2,YC2,xl,yl ) >get_rad ( XC1,YC1,xl,yl ):
				a,b=get_center ( XC2,YC2,xl,yl )
				print(str(a)+" "+str(b)+" "+str(get_rad ( XC2,YC2,xl,yl )))

			else :
				a,b=get_center ( XC1,YC1,xl,yl )
				print(str(a)+" "+str(b)+" "+str(get_rad ( XC1,YC1,xl,yl )))
		elif (float(yr - yl) ==0 and xr == xl):
			a,b=xr+R/2.0,yr
			print(float(a),end=" ")
			print(float(b),end=" ")
			print(R/2.0)
		elif (float(yr - yl) ==0):
			if (xr>xl):
				XC = xr+R
				YC = yr
			else :
				XC = xr-R
				YC = yr
			a,b=get_center ( XC,YC,xl,yl )
			print(float(a),end=" ")
			print(float(b),end=" ")
			print(float(get_rad ( XC,YC,xl,yl )))
		elif (float(xr - xl) ==0):
			if (yr>yl):
				YC = yr+R
				XC = xr
			else :
				YC = yr-R
				XC = xr
			a,b=get_center ( XC,YC,xl,yl )
			print(float(a),end=" ")
			print(float(b),end=" ")
			print(float(get_rad ( XC,YC,xl,yl )))

if __name__ == '__main__':
	main()

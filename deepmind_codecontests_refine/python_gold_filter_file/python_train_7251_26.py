import sys
import math


n,s=map(int,input().split())
time=[0 for i in range(n)]
diffa=[0 for j in range(n)]
gap=2*s+2
flag=False


for i in range(n):
    h,m=map(int,input().split())
    tota=h*60+m
    time[i]=tota

    if(n==1):
        if(tota>=s+1):
            print("0 0")
        else:
            hh=(tota+s+1)//60
            mm=(tota+s+1)%60
            print(hh,mm)
        break

    if(time[0]>s):
        print("0 0")
        break

    if(i>0):
        diffa[i]=time[i]-time[i-1]

        if(diffa[i]>=gap):
            flag=True
            hh=(time[i - 1] + s + 1)//60
            mm=(time[i-1]+s+1)%60
            print(hh,mm)
            break

        if (i==n-1 and flag==False):
            hh=(time[n-1]+s+1)//60
            mm=(time[n-1]+s+1)%60

            print(hh,mm)

#print(time)
#print(diffa)


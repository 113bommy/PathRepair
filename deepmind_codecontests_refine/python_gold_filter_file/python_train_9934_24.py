import os

time=input()
spend=input()
var=0
m=0
h=0
if int(time[3:])-int(spend[3:])<0:
	m=str(60+int(time[3:])-int(spend[3:]))
	var=1
else:
	m=str(int(time[3:])-int(spend[3:]))
if int(time[0:2])-int(spend[0:2])-var<0:
	h=str(24+int(time[0:2])-int(spend[0:2])-var)
else:
	h=str(int(time[0:2])-int(spend[0:2])-var)
if len(h)==1:
	h="0"+h
if len(m)==1:
	m="0"+m
print(h,end='')
print(":",end='')
print(m)

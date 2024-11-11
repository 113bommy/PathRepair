#coding=utf-8
a=int(input())
while True:
    aa=a
    s=0
    while aa>0:
        s+=aa%4
        aa//=10
    if s%4==0:
        print(a)
        break
    a+=1
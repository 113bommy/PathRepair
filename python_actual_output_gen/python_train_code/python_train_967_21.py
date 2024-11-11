a=[0,1,2]
n=int(input())
x=int(input())

while(n>7):
    n%=6

if(n==0): n=6


if(n==1): a=[1,0,2]
if(n==2): a=[1,2,0]
if(n==3): a=[2,1,0]
if(n==4): a=[2,0,1]
if(n==5): a=[0,2,1]
if(n==6): a=[0,1,2]

if(x==0):print(a[0])
if(x==1):print(a[1])
if(x==2):print(a[2])

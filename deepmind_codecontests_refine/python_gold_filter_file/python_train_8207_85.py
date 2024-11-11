x=int(input())
num=(x//11)*2
x%=11
if(x==0):print(num)
elif(x<=6):print(num+1)
else:print(num+2)

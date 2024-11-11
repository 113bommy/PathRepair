n,a,b,c=[int(i) for i in input().split()]
if(n%4==0):print("0")
elif(n%4==1):print(min(c,min(a+b,3*a)))
elif(n%4==2):print(min(b,min(2*a,2*c)))
else:print(min(a,3*c))

n,a,b,c= map(lambda x:int(x),input().split())
n=n%4
if n==1:    print(min(3*a,b+a,c))
elif n==2:    print(min(2*a,b,2*c))
elif n==3:    print(min(a,c*3,c+b))
else:    print(0)
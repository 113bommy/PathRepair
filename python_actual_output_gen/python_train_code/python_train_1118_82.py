a,b,k=map(int,input().split())
if k<=a:print(k-a,b)
elif a+b<k:print(0,0)
else:print(0,b-k+a)
a,b,c=map(int,input().split())
s=(a+b+c)/2
if (a+b+c)%2 or s-a<0 or s-b<0 or s-c<0:print("Impossible")
else:print(s-c,s-a,s-b)
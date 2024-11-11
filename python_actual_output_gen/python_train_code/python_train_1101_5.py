n,t = map(int,input().split())
a = ((pow(10,n-1)-1)//t)*t+t
print((a,-1)[a>=pow(10,n+1)])
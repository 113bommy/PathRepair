n=int(input());a=list(map(int,input().split()));a.sort()
if n%2==1:b=[0]+[(i+1)*2for i in range((n-1)//2)]*2
else:b=[1+i*2for i in range(n//2)]*2
b.sort()
if a!=b:print(0);exit()
else:print(((n//2)**2)%(10**9+7))
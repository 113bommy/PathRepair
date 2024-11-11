a,b,c=map(int,input().split())
k=int(input())
t=max(a,b,c)
print(a+b+c+(t*2**k)-t)
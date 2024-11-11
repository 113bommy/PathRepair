a,b,c,d=map(int, input().split())
z=min(b,d)-max(a,c)
print(z if z>0 else 0)
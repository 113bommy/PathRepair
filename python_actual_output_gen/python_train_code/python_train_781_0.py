a,b,c=map(int,input().split())
h=0
ans=min(a*2+b*2,a+b+c,b*2+c,a*2+c)
print(ans)
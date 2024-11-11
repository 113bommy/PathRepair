a,b,c,d,e=map(int,input().split())
ans=0
while(a>=1 and b>=1 and c>=2 and d>=7 and e>=4):
    ans+=1
    a-=1
    b-=1
    c-=2
    d-=7
    e-=4
print(ans)
import sys
input=sys.stdin.readline
l=input().split()
n=int(l[0])
m=int(l[1])
ans=0
for i in range(n):
    l=input().split()
    ti=int(l[0])
    Ti=int(l[1])
    xi=int(l[2])
    cost=int(l[3])
    if(ti>=Ti):
        ans+=(xi*m)
        ans+=cost
        continue
    maxcap=Ti-ti
    if(maxcap*xi<=cost):
        num1=0
        num1+=(xi*m)
        num1+=cost
        ans+=min(num1,((m+maxcap-1)//maxcap)*cost)
        continue
    ans+=(((m+maxcap-1)//maxcap)*cost)
print(ans)

n=int(input())
ans=0
l=[0]+list(map(int,input().split()))
for i in range(n):
    if l[i+1]-l[i]<=15:
        ans=l[i+1]+15
    else: ans=l[i]+15
if ans>90: ans=90
if l[0]>15:
    print(15)
else: print(ans)
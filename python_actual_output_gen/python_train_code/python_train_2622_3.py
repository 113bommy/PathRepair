n,m,k=[int(x) for x in input().split()]
temp=[]
for _ in range(n):
    arr=[int(x) for x in input().split()]
    for i in arr:
        temp.append(i)
temp.sort()
f=True
mid=temp[(n+m)//2]
#print(mid)
ans=0
for i in temp:
    if abs(mid-i)%k:
        f=False
        break
    else:
        ans+=(abs(mid-i)//k)
if f==False:
    print(-1)
else:
    print(ans)
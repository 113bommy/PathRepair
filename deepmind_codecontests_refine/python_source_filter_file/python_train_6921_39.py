n=int(input())
a=list(map(int,input().split()))
a.sort()
ans=0
wait=0
for i in a:
    if(i>=wait):
        ans+=1
    wait+=i
print(ans)
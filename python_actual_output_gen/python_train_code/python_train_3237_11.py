a, b=map(int, input().split())
ar=list(map(int, input().split()))

li=ar[b-1]
if(li==0): li+=1
cnt=0
for i in range(0, a-1):
    if(ar[i]>=li): cnt=cnt+1
print(cnt)
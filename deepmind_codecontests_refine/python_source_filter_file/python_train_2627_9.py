n=int(input())
arr=list(map(int, input().split()))
maxx=0
res=[]
for x in range(n):
    res.append(maxx+arr[x])
    maxx=max(maxx, arr[x])
print(*res)
N=int(input())
d=list(map(int,input().split()))

d.sort()
ans=d[N//2+1]-d[N//2]
print(ans)

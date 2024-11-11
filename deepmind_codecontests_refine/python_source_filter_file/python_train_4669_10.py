n=int(input())
a=[list(map(int,input().split())) for i in range(N)]
a.sort()
print(sum(a[0]))
n=int(input())
a=[i+1:int(input()) for i in range(n)]
v=1
for c in range(n):
    v=a[v]
    if v==2:
        print(c+1)
        break
else:
    print(-1)
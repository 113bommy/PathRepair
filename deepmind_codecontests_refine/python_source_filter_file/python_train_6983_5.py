n=int(input())
a=[[[0 for _ in range(10)]for _ in range(3)]for _ in range(4)]
for i in range(n):
    b,f,r,v=map(int, input().split())
    a[b-1][f-1][r-1]+=v
for bb in range(b):
    for ff in range(f):
        print(*a[bb][ff])
    if bb==2:
        break
    else:
        print("#"*20)

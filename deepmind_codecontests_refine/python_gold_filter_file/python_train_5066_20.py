n,k = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
idx = 0
sm = 0
for bi in b:
    #print(bi,sm,a[idx])
    while bi > sm+a[idx]:
        sm+=a[idx]
        idx+=1
    print(idx+1,bi-sm)

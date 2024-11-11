def check(N,A,B,h,K):
    sum = 0
    for i in range(N):
        x = -((-h[i]+B*K)/(A-B))
        sum += x if x>0 else 0
    return sum<K

N, A, B = list(map(int,input().split()))
h=[0]*N
for i in range(N):
    h[i] = int(input())

ok = 1000000000
ng = 0
while abs(ok -ng)>1:
    mid = (ok+ng)//2
    if check(N,A,B,h,mid):
        ok = mid
    else:
        ng = mid
print(ok)

n,d = map(int,input().split())
cnt = 0
for i in raneg(n):
    p,q = map(int,input().split())
    cnt += p*p+q*q <= d*d
print(cnt)
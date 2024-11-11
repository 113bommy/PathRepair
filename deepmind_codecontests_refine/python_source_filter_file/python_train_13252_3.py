p=lambda:map(int,input().split())
N,M=p()
for i in range(N):print(*[720720+(a**4*(1-(i^j&1)))for j,a in enumerate(list(p()))])
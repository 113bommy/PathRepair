n, k = map(int, input().split())
D = []

for d in range(2, int(n**.5)+1):
    while k>1 and n%d==0:
        n //= d
        D.append(d)
        k -= 1

if n==1:
    print(-1)
else:
    print(*D, n)
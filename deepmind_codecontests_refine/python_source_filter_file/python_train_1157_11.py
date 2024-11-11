n = int(input())
A = list(map(int, input().split()))

m = 99999
for x in range(n):
    tmp = sum([ 2*A[i]*( abs(i-x) + x + i) for i in range(n)])
    m = min(m, tmp)
print(m)
n = int(input())
A = list(map(int,input().split()))
c = [0]*10
add = 0
for i in range(n) :
    if A[i]>=3200 :
        add += 1
        continue
    a = A[i]//400
    c[a] = 1

print(sum(c),sum(c)+add)
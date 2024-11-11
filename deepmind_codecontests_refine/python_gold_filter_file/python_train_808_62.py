N = int(input())
A = [int(n) for n in input().split(' ')]
 
ans = 0
for i in range(60):
    x = 0
    for A_i in A:
        if A_i>>i&1:
            x += 1
    ans += x*(N-x)*2**i
ans = ans % (10**9+7)
print(ans)

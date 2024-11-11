N = int(input())
A = list(map(int, input().split()))
 
result = 0
for i in range(60):
    on = sum([(1 << i) & a for a in A]) >> i
    result += (on * (N - on)) << i
    result %= ((10**9) + 7)
 
print(result)
def solve(test):
    ans = 0
    n, k = map(int, input().split())
    ans = n // k
    print('YES' if ans % 2 == 1 else 'NO')
t = 1
#t = int(input())
for _ in range(t):
    solve(_ + 1)
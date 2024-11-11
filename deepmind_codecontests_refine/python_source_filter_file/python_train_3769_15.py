def solve(n, a):
    return sum(a) / n if sum(a) % n == 0 else sum(a) // n + 1
 
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    print(solve(n, a))
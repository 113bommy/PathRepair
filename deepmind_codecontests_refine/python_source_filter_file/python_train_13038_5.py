t = int(input())
for test in range(t):
    n, m = list(map(int, input().split()))
    a = n*m
    ans = a//2 + a%2
    print(a)
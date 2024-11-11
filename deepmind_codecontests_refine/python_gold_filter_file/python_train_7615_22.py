import sys
input = sys.stdin.readline

for zzz in range(int(input())):
    n, k = map(int, input().split())
    ans = 0
    while n != 0: 
        divisible = (n//k)*k
        ans += (n - divisible + 1)
        n = divisible//k
    print(ans-1)

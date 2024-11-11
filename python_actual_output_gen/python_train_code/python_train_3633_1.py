s = input()
n = int(input())
for _ in range(n):
    l, r, k = map(int, input().split())
    m = r - l +1
    k %= m
    s = s[:l-1] + s[r-k:r] + s[l-1:r-k] + s[r:]
    print(s)
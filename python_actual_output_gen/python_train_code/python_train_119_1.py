n = int(input())
a = list(map(int, input().split()))
r = n-1
for d in a:
    r += d
print(max(max(a), 1+r//n))

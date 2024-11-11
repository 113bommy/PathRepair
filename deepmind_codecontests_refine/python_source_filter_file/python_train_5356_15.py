p, n = map(int, input().split())
a = [-1 for i in range(p)]
for i in range(n):
    b = int(input())
    if a[b % p] != -1:
        print(i + 1)
        break
    else:
        a[b % p] = b
print(-1)
p, n = map(int, input().split())
used = []
for _ in range(p):
    used.append(0)
for i in range (n):
    x = int(input())
    if (used[(x%p)] == 1):
        print(i+1)
        quit()
    else:
        used[(x%p)] = 1
print(-1)
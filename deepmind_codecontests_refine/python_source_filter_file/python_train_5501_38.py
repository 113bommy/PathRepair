n, m, k = map(int, input().split())

for r in range(n+1):
    for  c in range(m+1):
        if k == c*(m-r) + r*(n-c):
            print('Yes')
            exit()

print('No')

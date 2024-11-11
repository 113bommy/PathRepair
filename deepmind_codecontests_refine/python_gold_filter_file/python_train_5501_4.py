n,m,k = map(int, input().split())

for h in range(n+1):
    for w in range(m+1):
        c = h*(m-w) + w*(n-h)
        if c==k:
            print("Yes")
            exit()
print("No")
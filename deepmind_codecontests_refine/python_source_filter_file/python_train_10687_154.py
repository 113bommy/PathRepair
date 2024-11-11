n,k=map(int,input().split())
for i in range(k-1):
    if str(n)[-1] != '0':
        n = n - 1
    else:
        n = n // 10

print(n)
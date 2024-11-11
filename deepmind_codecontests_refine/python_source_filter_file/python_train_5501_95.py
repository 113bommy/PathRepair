n, m, k = map(int, input().split())

cant = True
for i in range(n+1):
    for j in range(m+1):
        if n*i+m*j-2*i*j==k: cant = False
print("YNeos"[cant::2])
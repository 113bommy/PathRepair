N = int(input())
x = 0
for _ in range(N):
    k, u = input().split()
    k += float(x)*(380000 if u == 'BTC' else 1)
print(k)
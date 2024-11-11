n, m = map(int,input().split())
tot  = n * (n-1) // 2
if m >= tot:
    print("no solution")
    exit()
for i in range(n):
    print(i, 0)
# Tue Jul 07 2020 13:49:02 GMT+0300 (Москва, стандартное время)

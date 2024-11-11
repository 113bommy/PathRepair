n, m = map(int, input().split())
for i in range(m//n, 0, -1):
    rem = m-m//n*n
    if rem%i==0:
        print(i)
        break
n, m = input().split()
n = int(n)
m = int(m)
while m > 0:
    for i in range(1, n+1):
        if m >= i:
            m = m - i
            print(i, m)
        else:
            print(m)
            exit()
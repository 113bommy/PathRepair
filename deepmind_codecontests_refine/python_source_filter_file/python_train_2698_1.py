M = [20, 19]
Y = sum(M) * 5

for i in range(int(input())):
    res = 0
    y,m,d = list(map(int,input().split()))
    for y_2 in range(1000-1, y, -1):
        res += Y if y_2 % 3 != 0 else 200

    for m_2 in range(10, m, -1):
        res += M[m_2 % 2] if y % 3 != 0 else 20

    res += (M[m%2] if y % 3 != 0 else 20) - d +1

    print(res)
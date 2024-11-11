n = int(input())
x0, y0 = [int(i) for i in input().split()]

max_num = 10**9 + 1
N = ["A", max_num]
S = ["A", max_num]
W = ["A", max_num]
E = ["A", max_num]
NE = ["A", max_num]
NW = ["A", max_num]
SW = ["A", max_num]
SE = ["A", max_num]

for i in range(n):
    symbol, x, y = input().split()
    x = int(x)
    y = int(y)
    
    if x == x0:
        if y > y0:
            dist = y - y0
            if dist < N[1]:
                N[0] = symbol
                N[1] = dist
        else:
            dist = y0 - y
            if dist < S[1]:
                S[0] = symbol
                S[1] = dist
    elif y == y0:
        if x > x0:
            dist = x - x0
            if dist < W[1]:
                W[0] = symbol
                W[1] = dist

        else:
            dist = x0 - x
            if dist < E[1]:
                E[0] = symbol
                E[1] = dist
    elif y - y0 == x - x0:
        if y > y0:
            dist = y - y0
            if dist < NE[1]:
                NE[0] = symbol
                NE[1] = dist
        else:
            dist = y0 - y
            if dist < SW[1]:
                SW[0] = symbol
                SW[1] = dist
    elif y - y0 == x0 - x:
        if y > y0:
            dist = y - y0
            if dist < SE[1]:
                SE[0] = symbol
                SE[1] = dist
        else:
            dist = y0 - y
            if dist < NW[1]:
                NW[0] = symbol
                NW[1] = dist

if N[0] in "QR" or S[0] in "QR" or E[0] in "QR" or W[0] in "QR":
    print("YES")
elif NE[0] in "QB" or SE[0] in "QB" or SW[0] in "QB" or NW[0] in "QB":
    print("YES")
else:
    print("NO")
n = int(input())
A = [[int(i) for i in input().split()] for i in range(n)]
# A.sort(reverse = True, key = lambda x: x[2])

for i in range(101):
    for j in range(101):
        px, py, ph = A[0] # 高さ最大
        H = ph + abs(px - i) + abs(py - j)
        if all(h == max(H - abs(x - i) - abs(y - j) , 0) for x, y, h in A):
            print(i, j, H)
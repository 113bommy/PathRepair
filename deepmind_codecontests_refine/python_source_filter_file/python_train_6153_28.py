n, d = map(int, input().split())
elems = 0
m = int(input())
for i in range(m):
    x, y = map(int, input().split())
    q1 = x + d
    q2 = x - d
    q3 = -x + d
    q4 = -x + n + n - d
    print(q1,q2,q3,q4, y)
    if y <= q1 and y >= q2 and y >= q3 and y <= q4:
        print("YES")
    else: print("NO")
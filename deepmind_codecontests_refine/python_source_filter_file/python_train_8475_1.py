k = int(input())
a = []
for i in range(k):
    ai = []
    s = input()
    for ch in s:
        if ch != '.':
            ai.append(1)
        else:
            ai.append(0)
    a.append(ai)
failed = False
for i in range(k):
    for j in range(k):
        if a[i][j] == 1:
            if j == 0 or j == k - 1 or i > k - 3:
                failed = True
                break
            if a[i + 1][j - 1] == a[i + 1][j] == a[i + 1][j + 1] == a[i + 1][j] == 1:
                a[i][j] = 0
                a[i + 1][j - 1] = 0
                a[i + 1][j] = 0
                a[i + 1][j + 1] = 0
                a[i + 2][j] = 0
            else:
                failed = True
                break
    if failed:
        break
if not failed:
    print("YES")
else:
    print("NO")

n, k = map(int, input().split())

print("YES")
x = [["." for i in range(n)] for _ in range(4)]
curr = 1
if(k % 2 != 0):
    while k > 2 and curr != n // 2:
        x[1][curr] = "#"
        x[1][n - curr-1] = "#"
        curr += 1
        k -= 2
    curr = 1
    while k > 2 and curr != n // 2:
        x[2][curr] = "#"
        x[2][n - curr - 1] = "#"
        curr += 1
        k -= 2

    x[1][n//2] = "#"
else:
    curr = 1
    while k > 0:
        x[1][curr] = "#"
        x[1][curr] = "#"
        curr += 1
        k -= 2
for i in x:
    print(''.join(i))
    
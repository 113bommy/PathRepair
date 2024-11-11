x, y, a, b = list(map(int, input().split()))
count = 0
A = 2 * [0]
for i in range(a, b + 1):
    if i % x == 0 and i % y == 0:
        A[count] = i
        count += 1
    if count == 2:
        break
if count == 2:
    RR = A[1] - A[0]
    print(b // RR - a // RR + 1)
else:
    print(count)

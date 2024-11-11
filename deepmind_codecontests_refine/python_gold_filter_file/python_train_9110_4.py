n, m, s, d = map(int, input().split())
A = sorted(list(map(int, input().split())))

# Intervals
inv = []
prev = -1
for i in range(len(A)):
    if A[i] < m:
        inv.append((prev, A[i]))
        prev = A[i]
    else:
        inv.append((prev, m))
        break
if A[-1] < m:
    inv.append((A[-1], m))

output = [inv[-1]]

# Use of intervals
last = inv[-1]
for i in range(len(inv) - 2, -1, -1):
    a, b = inv[i], last
    if a[1] - a[0] >= s + 2 and b[0] - a[1] <= d - 2:
        last = inv[i]
        output.append(last)
output = output[::-1]

if m < A[0]:
    print("RUN " + str(m))
elif last[0] != -1 or A[0] <= s:
    print("IMPOSSIBLE")
else:
    last = 0
    for i in range(1, len(output)):
        a, b = output[i - 1], output[i]
        print("RUN " + str(a[1] - a[0] - 2))
        print("JUMP " + str(b[0] - a[1] + 2))
        last = b[0] + 1
    if last < m:
        print("RUN " + str(m - last))
N = int(input())
w, b = 0, 0
for n in range(N):
    cheese, color = input().split()
    if color == 'hard':
        b += 1
    else:
        w += 1
for k in range(1, 16):
    if b <= k**2 // 2 and w <= k**2 // 2 or \
    k % 2 == 1 and max(b, w) <= (k**2 + 1) // 2 and b + w <= k**2:
        print(k)
        break
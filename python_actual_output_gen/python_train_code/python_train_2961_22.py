q = int(input())
k = []
for i in range(q):
    k.append(int(input()))

for n in k:

    if n == 19:
        ans = 3
    elif n % 4 == 0:
        ans = (n // 4)
    elif n % 4 == 1:
        ans = (1 + ((n - 9) // 4))
    elif n % 4 == 2:
        ans = (1 + ((n - 6) // 4))
    else:
        ans = (2 + ((n - 15) // 4))

    if ans == 0:
        print(-1)
    else:
        print(ans)
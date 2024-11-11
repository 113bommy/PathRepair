n = int(input())

w = []
for _ in range(n):
    w.append(int(input()))

w.sort()

ans = n
j = n // 2
for i in range(n//2):

    while j < n:
        if 2 * w[i] <= w[j]:
            ans -=1
            j += 1
            break
        j += 1

    if j >= n:
        break

print(ans)

n = int(input())
a = sorted(map(int, input().split()))
j, k, a1, a2 = -1, -1, set(a), []
for i in a:
    if i == j == k:
        print('NO')
        exit()
    elif i == j:
        a2.append(i)
    j, k = i, j
print('YES')
print(len(a1), *a1)
print(len(a2), *reversed(a2))
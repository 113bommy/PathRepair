n = int(input())

for i in range(10**5):
    if 2 * n == i ** 2 - i:
        k = i
        break
    elif 2 * n < i ** 2 - i:
        print('No')
        exit()

k = int(k)
print('Yes')
print(k)
num, ans = 1, [[] for _ in range(k)]
for i in range(k):
    for j in range(i + 1, k):
        ans[i].append(num)
        ans[j].append(num)
        num += 1
    print(k - 1, *ans[i])

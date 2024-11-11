
n, k, m = map(int, input().split(' '))
a = list(map(int, input().split(' ')))

b = [0] * m
for i in a:
    b[i % m] += 1

for j in range(m):
    if b[j] >= k:
        print('Yes')
        count = k
        for x in a:
            if count == 0:
                break
            elif x % m == j:
                print(x, end=' ')
                count -= 1
        exit(0)


print('No')
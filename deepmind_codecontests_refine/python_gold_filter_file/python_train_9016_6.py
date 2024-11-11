n, k, m = list(map(int, input().split()))
digits = list(map(int, input().split()))

remainders = []
for i in range(m):
    remainders.append(int())

for i in range(len(digits)):
    remainders[digits[i] % m] += 1

for i in range(m):
    if remainders[i] >= k:
        print('Yes')
        for dig in digits:
            if dig % m == i:
                print(dig, end=' ')
                k -= 1
                if k == 0:
                    break
        exit()

print('No')

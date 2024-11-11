n, k = map(int, input().split())

alpha = 'abcdefghijklmnopqrstuwxyz'

pas = []

for i in range(k):
    pas.append(alpha[i % 25])


for i in range(n-k):
    if i > k:
        pas.append(pas[i % k])
    else:
        pas.append(pas[i])


print(''.join(pas))
def reverse(a, i):
    for j in range((i + 1) // 2):
        #print(j)
        a[j], a[i - j] = a[i - j], a[j]
    print(a)


n = int(input())
s = input()
a = list(s)

for i in range(2, n + 1):
    if n % i == 0:
        reverse(a, i - 1)
print(''.join(a))
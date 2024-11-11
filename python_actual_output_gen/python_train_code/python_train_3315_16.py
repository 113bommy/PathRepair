n = int(input())
a = list(map(int, input().split()))
odd = 0
even = 0

for i in range(0,2):
    if a[i] % 2 == 0:
        even += 1
    else:
        odd += 1
if even > odd:
    for i in range(0, n):
        if a[i] % 2 != 0:
            print(i + 1)
            break
else:
    for i in range(0, n):
        if a[i] % 2 == 0:
            print(i + 1)
            break

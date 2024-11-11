b, k = map(int, input().split())
a = list(map(int, input().split()))
odd = 0
for i in range(k):
    if a[i] % 2 == 1:
        odd += 1
if k % 2 == 1:
    print('eovdedn'[(odd % 2 == 1)::2])
else:
    print('eovdedn'[(a[k - 1] % 2 == 1)::2])
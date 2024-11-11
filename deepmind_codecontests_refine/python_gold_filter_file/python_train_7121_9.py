input()
A = input().split()
count5 = 0
for elem in A:
    if elem == '5':
        count5 += 1
count0 = len(A) - count5
if count0 == 0:
    print(-1)
else:
    print(int('5' * ((count5 // 9) * 9) + '0' * count0))

n = int(input())
a = input()
sum1 = 0
for i in range(n//2):
    if(a[i] == '?'):
        sum1 += 4.5
    else:
        sum1 += int(a[i])
for i in range(n//2, n):
    if(a[i] == '?'):
        sum1 -= 4.5
    else:
        sum1 -= int(a[i])
if(sum1 == 0):
    print('Bicarp')
else:
    print('Monocarp')
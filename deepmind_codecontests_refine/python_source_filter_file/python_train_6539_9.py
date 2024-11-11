n = int(input())
a = 0
for k in range(n):
    if int(input())//2 == 1:
        a = 1

if a == 1:
    print('first')
else:
    print('second')
n = int(input())
Mishka = Chris = 0
for i in range(n):
    a, b = [int(i) for i in input().split()]
    if a > b:
        Mishka += 1
    elif a < b:
        Chris += 1
if Mishka > Chris:
    print('Mishka')
elif Mishka < Chris:
    print('Chris')
else:
    print('Friendship is magic!^^')

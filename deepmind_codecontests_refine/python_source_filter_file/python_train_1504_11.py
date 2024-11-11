n = int(input())

i = - 10000000000
j = 10000000000

grt = ['>','>=']
lwr = ['<','<=']

for _ in range(n):
    sna =  input().split(' ')
    sign = sna[0]
    num = int(sna[1])
    ans = True if sna[2] == 'Y' else False
    if sign == '>':
        if ans:
            i = num + 1 if i < num +1 else i
        else:
            j = num  if j > num  else j
    elif sign == '>=':
        if ans:
            i = num if i < num  else i
        else:
            j =  num -1  if j > num -1 else j
    elif sign == '<':
        if ans:
            j = num - 1 if j > num -1 else j
        else:
            i = num  if i < num else i
    elif sign == '<=':
        if ans:
            j = num  if j > num else j
        else:
            i = num +1 if i < num +1  else i

# print(i,j)
if j >= i:
    print(i)
else:
    print("Impossible")
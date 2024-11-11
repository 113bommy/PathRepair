n = int(input())
a = [input().split('|') for i in range(n)]
answer = 'NO'
for i in range(n):
    if a [i][0] == 'OO':
        a[i][0] == '++'
        answer = 'YES'
        break
    elif a [i][0] == 'OO':
        a[i][0] == '++'
        answer = 'YES'
        break
print(answer)
if answer == 'YES':
    for x in a:
        print('|'.join(x))

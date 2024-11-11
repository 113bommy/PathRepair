a =int(input())
li = list(map(int, input().split()))
li.sort()
for i in range(0,a-2):

    if li[i]+li[i+1]>li[i+2]: print('YES');break
else: print('NO')

n = int(input())        # Кол-во раундов
mishka, chris = 0,0
for i in range(n):
    m,c = map(int,input().split())
    if m > c:
        mishka += 1
    elif c >m:
        chris += 1
if mishka > chris:
    print('Mishka')
elif mishka == chris:
    print('Friendship is magic!^^')
else:
    print('Chris')

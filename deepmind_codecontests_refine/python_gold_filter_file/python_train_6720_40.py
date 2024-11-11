n = int(input())
mishka = 0
chris = 0
 
for i in range(n):
    x, y = map(int, input().split())
    if x > y:
        mishka += 1 
    elif y > x:
        chris += 1
 
if mishka > chris:
    print('Mishka')
elif mishka == chris:
    print('Friendship is magic!^^')
else:
    print('Chris')
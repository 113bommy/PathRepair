n = int(input())

chris = 0
mishka = 0
for _ in range(n):
    m, c = map(int, input().split())
    if m > c: mishka += 1
    else: chris += 1

if chris > mishka:
    print('Chris')
elif mishka > chris:
    print('Mishka')
else:
    print('Friendship is magic!^^')
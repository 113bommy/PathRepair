n, c = map(int, input().split())
P = list(map(int, input().split()))
T = list(map(int, input().split()))
Limak = 0
Pade = 0
SL = []
SP = []
sl = 0
sp = 0
for i in range(n):
    sl += T[i]
    sp += T[n - i - 1]
    SL.append(sl)
    SP.append(sp)
for i in range(n):
    Limak += max(0, P[i] - SL[i] * c)
    Pade += max(0, P[n - i - 1] - SP[i] * c)
if Limak > Pade:
    print('Limak')
elif Pade > Limak:
    print('Padewoosh')
else:
    print('Tie')
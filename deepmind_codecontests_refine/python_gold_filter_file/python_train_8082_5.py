n = (input())
kol_vo_chet = 0
kol_vo_nechet = 0

nb = input().split()

for i in nb:
    if int(i, 10) % 2 == 0:
        kol_vo_chet += 1
    else:
        kol_vo_nechet += 1
answ = 0
answ = min(kol_vo_nechet, kol_vo_chet)
kol_vo_nechet -= answ

if kol_vo_nechet !=0:
    answ += kol_vo_nechet//3

print(answ)
n = int(input())

lista = list(map(int,input().split()))
listb = list(map(int,input().split()))

coua = [0]*6
coub = [0]*6

for v in lista:
    coua[v] +=1

for v in listb:
    coub[v] +=1

ok = True
ans = 0
for v in range(1,6):
    sumab = coua[v]+coub[v]
    if(sumab % 2 != 0):
        ok = False
        break
    ans += abs(coua[v]-sumab/2)

if not ok:
    print(-1)
else :
    print(ans//2)


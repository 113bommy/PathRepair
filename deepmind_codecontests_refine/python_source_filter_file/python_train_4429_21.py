n, m = map(int, input().split())
p = list(map(int, input().split()))
t = list(map(int, input().split()))
curtime = 0
lim = 0
rade = 0
for i in range(n):
    curtime += t[i]
    lim += max(0, p[i] - m*curtime)
curtime = 0
for i in range(n-1, 0, -1):
    curtime += t[i]
    rade += max(0, p[i] - m*curtime)
if(rade > lim):
    print('Radewoosh')
elif(lim > rade):
    print('Limak')
else:
    print('Tie')

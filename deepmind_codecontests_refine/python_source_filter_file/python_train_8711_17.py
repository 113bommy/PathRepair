n = int(input())
Po, Ti, Sp, So, Re, Mi = 0, 0, 0, 0, 0, 0

for i in range(n):
    x = input()
    if x == 'purple':
        Po = 1
    elif x == 'green':
        Ti = 1
    elif x == 'blue':
        Sp = 1
    elif x == 'orange':
        So = 1
    elif x == 'red':
        Re = 1
    else:
        Mi = 1

ans = []
if Po == 0: ans += ["Power"]
if Ti == 0: ans += ["Time"]
if Sp == 0: ans += ["Power"]
if So == 0: ans += ["Soul"]
if Re == 0: ans += ["Reality"]
if Mi == 0: ans += ["Mind"]
print(len(ans))
for a in ans:
    print(a)        
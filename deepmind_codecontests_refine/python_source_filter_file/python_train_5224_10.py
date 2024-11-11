sosatb = []
ans = ''
count = int(input())
inputs = input()
inputs = list(inputs)
for i in range(0,10):
    sosatb.append(0)
for choose in inputs:
    if choose == 'L':
        dex = sosatb.index(0)
        sosatb[dex] = 1
    elif choose == 'R':
        sosatb.reverse()
        dex = sosatb.index(0)
        sosatb[dex] = 1
        sosatb.reverse()
    else:
        a = int(choose)
        sosatb[a] = 0
for i in sosatb:
    ans = ans+str(i)
print(int(ans))

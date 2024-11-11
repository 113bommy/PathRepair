naborov = int(input())

sets = []
for _ in range(naborov):
    input()
    l = input().split()
    sets.append([int(ll) for ll in l])
    
def check(s):
    summa = sum(s)
    if summa == 0: 
        return ('NO', None)
    elif summa > 0:
        s.sort(reverse=True)
    else:
        s.sort()
    return ('YES', s)

for s in sets:
    ch = check(s)
    print(ch[0])
    if ch[0] == 'YES': print(' '.join([str(s) for s in ch[1]]))
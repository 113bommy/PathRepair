N, = list(map(int,input().split()))
a  = list(map(int,input().split()))
s = set()
c6=0
for ai in a:
    if ai>=3200:
        c6 += 1
    else:
        s |= set({ai//400})
print(len(s),len(s)+c6)
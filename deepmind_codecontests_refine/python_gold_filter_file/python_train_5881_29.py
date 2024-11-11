
''' combination lock 540a '''
input()
f = lambda : [int(x) for x in input()]
org = f(); key = f(); turn = 0
for o,k in zip(org,key):
    turn+=min(abs(o-k),abs(10-abs(o-k)))
print(turn)


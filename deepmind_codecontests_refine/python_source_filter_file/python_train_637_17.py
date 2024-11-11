

a,b = map( int , input().split() )
l1 = list(map(int , input().split()))
l2 = list(map(int , input().split()))
ev1,ev2,odd1,odd2 = 0,0,0,0
for x in l1:
    if x&1:
        odd1 += 1
    else:
        ev1 += 1
for x in l2:
    if x&1:
        odd2 += 1
    else:
        ev2 += 1
ans = min(ev1,odd1)
ans += min(ev2 , odd2)
print(ans)

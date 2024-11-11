n = int(input())

a = []
for x in input().split():
    bid = int(x)
    while bid % 2 == 0:
        bid /= 2
    while bid % 3 == 0:
        bid /= 3
    a.append(bid)

val = a[0]
jackpot = True
for i in range(1, n):
    if a[i] != val:
        jackpot = False
        break

if jackpot:
    print ("YES")
else:
    print ("NO")        
    
    
    

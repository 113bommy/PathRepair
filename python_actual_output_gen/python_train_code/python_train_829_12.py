n,m,k = [int(x) for x in input().split(' ')]
houses = [int(house) for house in input().split(' ')]

buyL = False
buyR = False
buyLpos = 9999999
buyRpos = 9999999

#Left of M
for i in range(m-1,0,-1):
    if houses[i] <= k and houses[i] != 0:
        buyL = houses[i]
        buyLpos = i
        break

#Right of M    
for i in range(m,len(houses)):
    if houses[i] <= k and houses[i] != 0:
        buyR = houses[i]
        buyRpos = i
        break

disR = abs((buyRpos+1) - m)
disL = abs(m - (buyLpos+1))

ans = min(disL,disR)
ans *= 10
print(ans)

n,h,m = map(int,input().split())
houses = [h]*(n+1)
for _ in range(0,m):
    l,r,x = map(int,input().split())
    for i in range(l,r+1):
        if houses[i] < x and houses[i] != h :
            pass
        else:
            houses[i] = x
#print(houses)
profit = 0
for i in range(1,len(houses)):
    profit += houses[i]**2
print(profit)

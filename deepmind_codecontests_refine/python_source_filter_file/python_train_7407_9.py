#take input
n = int(input())
superierList = []
for i in range(n):
    superierList.append(int(input()))
print(superierList)
orderList = [1]*n

for i in range(n):
    thisSup = superierList[i]
    thisOrder = orderList[i]
    while (thisSup != -1):
        updateOrder = thisOrder+1
        if(updateOrder<orderList[thisSup-1]):
            thisSup = -1
        else:
            orderList[thisSup-1] = updateOrder
            thisSup = superierList[thisSup-1]
            thisOrder = updateOrder

print(max(orderList))
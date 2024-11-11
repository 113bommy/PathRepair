
n,m,k = [int(s) for s in input().split()]

BuyingPrice = []
SellingPrice = []
Number_of_items = []
for i in range(n):
    input()
    x = []
    y = []
    z = []
    for j in range(m):
        a,b,c = [int(s) for s in input().split()]
        x.append(a)
        y.append(b)
        z.append(c)
    BuyingPrice.append(x)
    SellingPrice.append(y)
    Number_of_items.append(z)
def getProfit(i,j):
    def takeFirst(z):
        return z[0]
    n = []
    for w in range(m):
        n.append((SellingPrice[j][w]-BuyingPrice[i][w],Number_of_items[i][w]))
    n.sort(key=takeFirst,reverse=True)

    count = 0
    profit = 0
    for w in n:
        if count>=k:
            break
        profit += min(w[1],k-count)*max(w[0],0)
        if(w[0] > 0):
            count += min(w[1],k-count)
    return profit

profit = 0
for i in range(n):
    for j in range(m):
        profit = max(profit,getProfit(i,j))
print(profit)


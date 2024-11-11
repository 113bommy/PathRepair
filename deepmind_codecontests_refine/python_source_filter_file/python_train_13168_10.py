def search(a, key):

    for i in range(len(a)):

        if key == a[i].price:
            return i

    return -1

def insert_max(a, key):

    size = len(a)

    i = 0
    while i < size:
        if key.price > a[i].price:
            break
        i += 1
    
    for j in reversed(range(i, size-1)):
        a [j+1] = a[j]

    if i != size:
        a[i] = key

def insert_min(a, key):

    size = len(a)

    i = 0
    while i < size:
        if key.price < a[i].price:
            break
        i += 1
    
    for j in reversed(range(i, size-1)):
        a [j+1] = a[j]

    if i != size:
        a[i] = key

class Buy:

    def __init__(self, price, vol):
        
        self.price = price
        self.vol = vol

class Sell:

    def __init__(self, price, vol):
        
        self.price = price
        self.vol = vol

n,s = map(int, input().split())
buy = []
sell = []
best_buy = s * [Sell(0,0)]
best_sell = s * [Sell(100001,0)]
cb = 0
cs = 0

for i in range(n):
    d, p, v = input().split()
    
    price = int(p)
    vol = int(v)
    
    if d == 'B':
        ind = search(buy, price)
        
        if ind == -1:
            obj = Buy(price, vol)
            buy.append(obj)
            cb += 1
            insert_max(best_buy, obj)

        else:
            buy[ind].vol += vol
        
    else:
        ind = search(sell, price)
                      
        if ind == -1:
            obj = Sell(price, vol)
            sell.append(obj)
            cs += 1
            insert_min(best_sell, obj)
            
        else:
            sell[ind].vol += vol

if cb > s:
    cb = s
if cs > s:
    cs = s
    
for i in reversed(range(cs)):
    print('S' + ' ' + str(best_sell[i].price) + ' ' + str(best_sell[i].vol))       
                     
for i in range(cb):
    print('B' + ' ' + str(best_buy[i].price) + ' ' + str(best_buy[i].vol))

    
    


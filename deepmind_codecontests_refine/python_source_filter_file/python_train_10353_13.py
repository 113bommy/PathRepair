n,k = input().split()
n = int(n)
k = int(k)
dealnum = 0
dealers = []
for i in range(n):
    prices = [int(i) for i in input().split()]
    for j in range(1,len(prices)):
        if prices[j] < k:
            dealnum += 1
            dealers.append(str(prices[0]))
            break
print(dealnum)
print(' '.join(dealers))
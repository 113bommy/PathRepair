# Python 3
import bisect

prices = []
n = int(input())

#for price in (int(x) for x in input().split(" ")):
#    bisect.insort(prices, price)
    
price = [int(x) for x in input().split(" ")]
price.sort()

days = int(input())

#cache = {}
#def check(coin, guess):
#    if coin == 0:
#        return True
#    
#    if guess in cache:
#        if cache[guess] <= coin:
#            return True
#        
#    if prices[guess-1] <= coin:
#        if guess not in cache or cache[guess] > coin:
#            cache[guess] = coin
#            
#        return True
#    
#    return False
        
cache2 = {}
for _ in range(days):
    coins = int(input())
    print(bisect.bisect_right(prices, coins))
#    if coins in cache2:
#        print(cache2[coins])
#        continue
#    
#    low = 0
#    high = len(prices)
#    
#    if not check(coins, low+1):
#        print(low)
#        cache2[coins] = low
#        continue
#    
#    if check(coins, high):
#        print(high)
#        cache2[coins] = high
#        continue
#    
#    while(low + 1 < high):
#        mid = low + (high - low) // 2
#        if (check(coins, mid)):
#            low = mid
#        else:
#            high = mid
#    
#    if not check(coins, high):
#        print(low)
#        cache2[coins] = low
#    else:
#        print(high)
#        cache2[coins] = high
    
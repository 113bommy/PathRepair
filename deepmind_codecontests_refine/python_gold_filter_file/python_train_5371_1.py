import math
from functools import reduce

n = int(input())
numbers = [int(x) for x in input().split()]
print('YES')
gcd = reduce(math.gcd, numbers)
if gcd != 1:
    print(0)
else:
    ans = 0
    line_of_odds = 0
    for num in numbers:
        if num % 2 == 1:
            line_of_odds += 1
        else:
            ans += line_of_odds // 2 + 2 * (line_of_odds % 2)
            line_of_odds = 0
    ans += line_of_odds // 2 + 2 * (line_of_odds % 2)
    print(ans)
     
        
            
            
    
        
                
        
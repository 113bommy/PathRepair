#imgur.com/Pkt7iIf.png

#n, m = map(int, input().split())
#n = int(input())
#d = list(map(int, input().split()))

import math
n = int(input())
print(math.ceil(n/4)-1) if n%2 == 1 else print (0)
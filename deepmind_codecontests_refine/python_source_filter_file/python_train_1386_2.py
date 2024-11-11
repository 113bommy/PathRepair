import sys
from collections import defaultdict
from itertools import islice
 
_ = input()
numbers_str = input()
numbers = [int(n) for n in numbers_str.strip().split()]
 
sums = {}
for i, a in enumerate(numbers, start=1):
    for j, b in enumerate(islice(numbers, i + 1, None), start=i + 1):
        if a + b in sums:
            indexes = sums[a + b]
            if i in indexes or j in indexes:
                continue
            print("YES")
            x, y = indexes
            print(x, y, i, j)
            sys.exit()
        else:
            sums[a + b] = (i, j)
        
 
else:
    print("NO")
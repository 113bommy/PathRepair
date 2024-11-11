"""
    Author : thekushalghosh
    Team   : CodeDiggers
"""
import sys
q,w = map(int,input().split())
for i in range(q + 1,w):
    if len(set(list(str(i)))) == len(list(str(i))):
        print(i)
        sys.exit()
print(-1)

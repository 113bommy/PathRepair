import math
import sys

#imgur.com/Pkt7iIf.png

#n, m = map(int, input().split())
#n = int(input())
#d = list(map(int, input().split()))

a, b, c, d = list(map(int, input().split()))

if a*d < c*b:
    t = math.gcd((b*c-a*d),(b*c))
    print((b*c-a*d)//t, '/', (b*c)//t, sep = '')
else:
    t = math.gcd((a*d-b*c),(a*d))
    print((a*d-b*c)//t, '/', (a*d)//t, sep = '')
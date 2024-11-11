import sys
import math

line1 = sys.stdin.readline().strip()
line2 = sys.stdin.readline().strip()

a, b = line1.split()

w, h = int(a), int(b)

w, h

heights = line2.split()
heights = list(map(lambda l: int(l), heights))

h = min(max(heights), h)

heights = list(filter(lambda h: h>0, heights))

w = min(len(heights), w)

#print(w, h)
wtc = w
htc = h

needed = 0

if w == 1:
    print(0)
else:
    heights.sort(reverse=True)
    for i in range(len(heights)):
        if i == len(heights) - 1:
            curr_h = heights[i]
            if htc < 0:
                needed += 1
            else:
                needed += htc
            
        else:
            dh = htc - heights[i+1]
            
            if dh > 0:
                htc -= dh
                needed += dh
            elif dh == 0:
                htc -= 1
                needed += 1
            else:
                htc -= 1
                needed += 1

    print(sum(heights) - needed)
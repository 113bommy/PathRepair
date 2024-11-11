line1 = input()
line2 = input()
dc = [int(s) for s in line1.split(' ')]
fc = [int(s) for s in line2.split(' ')]
d = [abs(a - b) for a, b in zip(dc, fc)]
transit_x = max(2, d[0]+1)*2
transit_y = max(2, d[1]+1)*2
t = transit_x + transit_y
print(t)
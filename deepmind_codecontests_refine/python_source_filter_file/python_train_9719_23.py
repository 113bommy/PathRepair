import math
line = list(map(int,input().split()))
ab = line[0]
bc = line[1]
ac = line[2]
a = math.sqrt((ab * ac) / bc)
b = math.sqrt((ab * bc) / ac)
c = math.sqrt((bc * ac) / ab)
print(3 * int(a + b + c))
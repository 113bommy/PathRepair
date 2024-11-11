import math
n = int(input())
a = [0, 0]
vallist = []
for item in range(n):
    x, y = list(map(int, input().split()))
    vals = [x, y]
    vallist.append(vals)
print(sum(sorted(vallist,key=lambda x:x[0+1])[-1]))
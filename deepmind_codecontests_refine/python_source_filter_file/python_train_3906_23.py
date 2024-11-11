import math

n, s = [int(x) for x in input().split()]
pas = []
for i in range(n):
    f, t = [int(x) for x in input().split()]
    pas.append((t,f))
pas.sort(key = lambda pair : pair[0] + pair[1])
print(pas[-1][0] + pas[-1][1])

    

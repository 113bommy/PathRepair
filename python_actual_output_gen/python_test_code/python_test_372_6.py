from math import floor, ceil
n = int(input())
l = []
for i in range(n):
    l.append(input()[0])
m = {x:0 for x in l}
for i in l:
    m[i]+=1
minp = 0
for i in m:
    minp+=floor(m[i]/2)*(floor(m[i]/2)-1)/2 + ceil(m[i]/2)*(ceil(m[i])/2-1)/2
print(int(minp))
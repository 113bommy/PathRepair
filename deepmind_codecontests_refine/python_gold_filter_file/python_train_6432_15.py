N = int(input())
xlist = list(map(int, input().split()))
p = round(sum(xlist) / N)
s = 0
for x in xlist:
    s += (x-p)**2
print(s)
x=int(input())
y=list(map(str,input().split()[:x]))

y = [int(x) for x in y]
y.sort()
print(y)

e=0
for n in range(x-1):
    e=e+ (y[x-1] - y[n])
print(e)    
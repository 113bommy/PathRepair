
n,m = [int(i) for i in input().split(' ')]
a = sorted([int(i) for i in input().split(' ')])

x = 0
v = 0
for i in a:
    if i<0 and v<m:
        x+=(i*(-1))
        v+=1
print(x)

def ms(x, y):
    if y <= x:
        return x-y
    return x + n - y

n,m=[int(x) for x in input().split()]
d = [int(x) for x in input().split()]

a=0
c=1

for x in d:
    a += ms(x,c)
    c=x
print(a)

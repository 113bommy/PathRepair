s = input().split(' ')
n = int(s[0])
m = int(s[1])

p1 = set([ int(i) for i in input().split(' ')])
p2 = set([ int(i) for i in input().split(' ')])
inter = p1&p2
b = False
if len(inter) > 0:
    b = True
    minA = min(inter)

min1, min2 = min(p1), min(p2)

if b:
    print(minA)
elif p1 > p2:
    print(min2*10+min1)
else:
    print(min1*10+min2)

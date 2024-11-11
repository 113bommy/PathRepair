left = []
right = []
for  _ in range(int(input())):
    l,r = map(int,input().split())
    left.append(l)
    right.append(r)
c = 0
if left.count(1) > left.count(0):
    c+=(len(left) - left.count(1))
elif left.count(1) < left.count(0):
    c+=(len(left) - left.count(0))
else:
    c+=(len(left)//2)

if right.count(1) > right.count(0):
    c+=(len(right) - right.count(1) )
elif left.count(1) < left.count(0):
    c+=(len(right) - right.count(0))
else:
    c+=(len(right)//2)
print(c)

    
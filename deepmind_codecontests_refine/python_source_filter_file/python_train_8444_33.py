list1 = input().split()
f = 0
y, b, r = int(list1[0]), int(list1[1]), int(list1[2])
A = min(y, b, r)
if A == y:
    f = y*3 + 3
elif A == b:
    f = b*3
elif A == r:
    f = r*3 - 3
print(f)
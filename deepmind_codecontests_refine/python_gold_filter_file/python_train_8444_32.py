list1 = input().split()
f = 0
y, b, r = int(list1[0]), int(list1[1]), int(list1[2])
A = min(y, b-1, r-2)
if A == y:
    f = y*3 + 3
elif A == b-1:
    f = b*3
elif A == r-2:
    f = r*3 - 3
print(f)
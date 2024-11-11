n = int(input())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
l1, l2 = -1, -1
t = sum(a)
for i in b:
    if i > l2:
        l2 = i
    if l2 > l1:
        l1, l2 = l2, l1

if t < l1 + l2:
    print("YES")
else:
    print("NO")

n = int(input())
s1 = [int(i) for i in input().split()]
s1.pop(0)
s2 = [int(i) for i in input().split()]
s2.pop(0)
t = 0
while s1 and s2:
    t += 1
    a = s1.pop(0)
    b = s2.pop(0)
    if a > b:
        s1.append(b)
        s1.append(a)
    else:
        s2.append(a)
        s2.append(b)
    if t>1000:
        break
if t>100:
    print(-1)
else:
    if s1:
        print(t, 1)
    else:
        print(t, 2)

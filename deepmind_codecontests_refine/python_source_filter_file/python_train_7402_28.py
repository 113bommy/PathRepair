x=int(input())

t=[]
if x % 3 == 0 or x % 3 == 1 :
    t.append(1)
    t.append(1)
    u = x - 2
    t.append(u)
    print(t)
else:
    t.append(2)
    t.append(1)
    u = x - 3
    t.append(u)
    print(*t)

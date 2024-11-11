n = int(input())
k = []
t = list(map(int, input().rstrip()))
for i in range(n):
    if t[i] == 2:
        k.append(2)
    elif t[i] == 3:
        k.append(3)
    elif t[i] == 4:
        k.append(3)
        k.append(2)
        k.append(2)
    elif t[i] == 5:
        k.append(5)
    elif t[i] == 6:
        k.append(5)
        k.append(3)
        
    elif t[i] == 7:
        k.append(3)
    elif t[i] == 8:
        k.append(7)
        k.append(2)
        k.append(2)
        k.append(2)
    elif t[i] ==9:
        k.append(7)
        k.append(3)
        k.append(3)
        k.append(2)
    else:
        a =0
k.sort()
k.reverse()
for j in range(len(k)):
    print(k[j],end="")
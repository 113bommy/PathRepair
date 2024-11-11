t = int(input())
mas=[]
m=[]
for i in range(t):
    n, x = [int(i) for i in input().split()]
    d=[0]*n
    h=[0]*n
    for j in range(n):
        d[j], h[j] = [int(j) for j in input().split()]
        mas.append(d[j] - h[j])
    M1=max(mas)
    M2=max(d)
    if M2 > x:
        m.append(1)
    elif M1 > 0:
        if (x + M1 - M2) % M1 == 0:
            m.append((x + M1 - M2)//M1)
        else:
            m.append((x + M1 - M2)//M1 + 1)
    else:
        m.append(-1)
    mas=[]
for i in m:
    print(i)
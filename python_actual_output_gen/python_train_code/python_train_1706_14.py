n = int(input())
k1 = list(map(int, input().split()))
k1.pop(0)
k2 = list(map(int, input().split()))
k2.pop(0)
trick = 0
while k1 and k2:
    trick+=1
    if trick>100:
        print(-1)
        exit()
    a = k1.pop(0)
    b = k2.pop(0)
    if a > b:
        k1.append(b)
        k1.append(a)
    else:
        k2.append(a)
        k2.append(b)
print(str(trick) + " " + str(1 if k1 else 2))

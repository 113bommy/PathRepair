k1, k2, k3 = map(int, input().split())

'''
if min(k1, k2, k3) == 1:
    print("YES")
'''

if (k2 >= k1) and (k2 >= k3):
    k1, k2, k3 = k2, k1, k3
elif (k3 >= k1) and (k3 >= k2):
    k1, k2, k3 = k3, k1, k2

#print(k1, k2, k3)

def get(k1, k2, k3):
    MAX = 15000
    L = [0]*MAX
    for i in range(MAX):
        if i*k1 >= MAX:
            break
        L[i*k1] = 1

    z = MAX - 1
    for i in range(MAX):
        if L[i] == 0:
            z = i
            break

    #print(z)
    for i in range(MAX):
        if z + i*k2 >= MAX:
            break
        L[z + i*k2] = 2

    z = MAX - 1
    for i in range(MAX):
        if L[i] == 0:
            z = i
            break
    #print(z)

    for i in range(MAX):
        if z + i*k3 >= MAX:
            break
        L[z + i*k3] = 3

    z = MAX - 1
    for i in range(MAX):
        if L[i] == 0:
            z = i
            break
    #print(z)
    #print(L[:50])
    if z < MAX - 1:
        return 0
    else:
        return 1

RES1=get(k1, k2, k3)
RES2=get(k1, k3, k2)

if RES1 and RES2:
    print("YES")
else:
    print("NO")

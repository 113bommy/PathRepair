_1 = tuple(map(int,input().split()))
_2 = tuple(map(int,input().split()))
_3 = tuple(map(int,input().split()))
def in_rect(x,a):
    if a[0] <= x[0] <= a[2] and a[1] <= x[1] <= a[3]:
        return True
    return False
def inter(w,b):
    kib = kab = kia = kaa = False
    temp = 0
    if in_rect((w[0],w[1]),b):
        temp += 1
        kib = True
    if in_rect((w[0],w[3]),b):
        temp += 1
        kia = True
    if in_rect((w[2],w[1]),b):
        temp += 1
        kab = True
    if in_rect((w[2],w[3]),b):
        temp += 1
        kaa = True
    return (temp,kib,kia,kab,kaa)
inter1 = inter(_1,_2)
inter2 = inter(_1,_3)
s = inter1[0]+inter2[0]
for i in range(1,5):
    if inter1[i] == inter2[i] == True:s -= 1
if s < 4:
    print('YES')
    exit(0)
if inter1[0] >= 3 or inter1[0] >= 3:
    print('NO')
    exit(0)
if inter1[1] == inter1[2] == inter2[3] == inter2[4] == True:
    if _2[2] >= _3[0]:print('NO')
    else:print('YES')
elif inter1[1] == inter2[2] == inter1[3] == inter2[4] == True:
    if _2[3] >= _3[1]:print('NO')
    else:print('YES')
elif inter2[1] == inter2[2] == inter1[3] == inter1[4] == True:
    if _3[2] >= _2[0]:print('NO')
    else:print('YES')
elif inter2[1] == inter1[2] == inter2[3] == inter1[4] == True:
    if _3[3] >= _2[1]:print('NO')
    else:print('YES')

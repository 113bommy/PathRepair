t = int(input())
def F(a):
    schet = 0
    for i in range(len(a)):
        if a[i] == '0' and i ==0:
            schet+=1
        if a[i] == '0':
            if a[i] != a[i-1]:
                schet+=1
    if schet == 0:
        return 0
    elif schet==1:
        return 1
    else:
        return 2
for i in range(t):
    s = ''
    s = input()
    print(F(s))
'''
n = int(input())
def slove(a):
    for i in range(10**(a - 1), 10 **a):
        k = str(i)
        if k.count('0') == 0:
            for j in k:
                if i % int(j) == 0:
                    break
            else:
                return i
    else:
        return -1
for i in range(0,n):
    a = int(input())
    print(slove(a))
'''
def slove(a):
    res = '2'
    if a - 1 == 0:
        return -1
    if (a - 1)% 3 == 0:
        return res * (a - 1) + '7'
    else:
        return res * (a - 1) + '3'
n = int(input())
for i in range(0,n):
    a = int(input())
    print(slove(a))
import sys, os, math

def er(k):
    a = [True for i in range(k + 1)]
    a[0] = a[1] = False
    global p
    p = [2]
    m = 2
    while m < k:
        for i in range(k // m):
            a[(i + 1) * m] = False
        a[m] = True
        i = m + 1
        while (not a[i]) & (i < k): i = i + 1
        if i < k:
            m = i
            p.append(m)
        else:
            m = k + 1


def lucky(string):
    global p
    n = len(string)
    for num in p:
        if (num > n):
            return 0
        elif (n % num == 0):
            for i in range(n // num):
                if sum(list(map(int,string[i::n//num])))==num:
                    return 1




p = [2]
er(100000)
p.insert(1,4)
p.remove(2)
n = map(int, input())
st = input().replace(" ", "")
if lucky(st):
    print("YES")
else:
    print("NO")
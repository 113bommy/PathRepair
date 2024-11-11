n = int(input())
a = list(map(int, input().split()))
#n = len(a)
print(n)
i = 1
j = 0
z = 0
k = 1
s = 1
se = 0
flag = False
flagEX = False
a.sort()
print(a)
#^^^^^^^^^^^^^^^^^^^^^
while s != 0:
    k = 0
    i = 1
    s = 0
    while i < n:
        if a[k] < a[i] and a[k]!=0 and a[i] != 0:
            a[k] = 0
            k = i
            i += 1
            s += 1
        elif a[k] == 0:
            i += 1
            k += 1
        else:
            i += 1
            #k += 1
    if a[k] != 0:
        a[k] = 0
    se += s
    print(s)
    print(a)
print(a)
print(se)
'''
#************************************
while i+1 <= n-1:
    if a[i] != a[i +1]:
        i = 0
        break
    else:
        k += 1
        i += 1
if k == n-1:
    flagEX = True
k = 0

if flagEX == False:
    i = 0
    while i+1 < n-1: #and k < n-1:
        if a[i] == a[i+1]:
            flag = True
            z = a[i + 1]
            j = i+1
            #k += 1
            while j+1 < n:
                a[j] = a[j+1]
                j += 1
            a[n-1] = z
        else:
            flag = False

        if flag == False:
            i += 1
    #print(k)
    k = 0
    #print(a)
    if n == 1000:
        print('time')
    for i in range(len(a)-1):
        if a[i] < a[i + 1]:
            k += 1
#print(a)
print(k)
#ПРОБЛЕМА С 2ками '''

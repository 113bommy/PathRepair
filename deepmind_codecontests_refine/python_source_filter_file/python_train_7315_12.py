import math
'''

def arraysum(array1, array2):
    allsum = 0
    for i in range(len(array1)):
        allsum += abs(array1[i] - array2[i])

    
m = int(input())
for i in range(m):
    s= input().split(' ')
    n=int(s[0])
    x=int(s[1])
    y=int(s[2])
    sh=y-x
    a=[]
    for j in range(1,sh):
        if sh%j==0:
            a.append(j)
    p=0
    for it in a:
        if it*n-1>=sh:
            p=it
            break
    b=[]
    for j in range(0,n):
        b.append(j*p+1)
    for j in range(len(b)):
        print(b[j],' ',end='')
    print()
'''
'''
n = int(input())
for i in range(n):
    m = int(input())
    s = input().split(' ')
    a = []
    for c in s:
        a.append(int(c))
    asort = a
    asort.sort()
    nullitem = 0
    print(asort)
    for i in range(m - 1):
        if asort[i] - asort[i - 1] > 1:
            nullitem = asort[i] + 1
            break
    asort.append(-1)
    array1 = []
    tmp = 1
    for i in range(len(asort) - 1):
        if asort[i] != asort[i + 1]:
            array1.append((tmp, asort[i]))
            tmp = 1
        else:
            tmp += 1
    print(nullitem)
    mi1 = 0
    array1.sort(key = lambda i: i[1])
    for i in range(len(array1)):
        if array1[i][0] == 1:
            if array1[i][1] > mi1:
                mi1 = array1[i][1]
            break
    print(mi1 + nullitem)
    print()
'''
'''
n = int(input())
for i in range(n):
    s = input().split(' ')
    x = int(s[0])
    y = int(s[1])
    k = int(s[2])
    oper = k 
    palki = k * y + k
    oper += math.ceil((palki - 1) / (x - 1)) 
    print(oper)
'''
'''
s = input().split(' ')
h = int(s[0])
n = int(s[1])
s1 = input().split(' ')
a = []
for c in s1:
    a.append(int(c))
ar = []
o = 0
for i in range(n):
    o = 0
    f = False
    for j in range(a[i] * 2):
        
        if o >= a[i]:
            f = True
        if f:
            o -= 1
            ar.append('.' * (h - o - 1) + '\\' + '#' * o)
        else:
            ar.append('.' * (h - o - 1) + '/' + '#' * o)
            o += 1
        
for i in range(len(ar[0])):
    for j in range(len(ar)):
        print(ar[j][i], end = '')
        
    print()
'''
n = int(input())
for i in range(n):
    m = int(input())
    s = input().split(' ')
    a = []
    for item in s:
        a.append(int(item))
    f = False
    for i in range(m - 1):
        if a[i] < a[i + 1]:
            f = True
    a.sort()
    if f or a[0] == a[-1]:
        print('YES')
    else:
        print('NO')
    
    
        


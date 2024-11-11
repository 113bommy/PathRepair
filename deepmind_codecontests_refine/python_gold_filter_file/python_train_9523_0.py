'''
Created on Feb 11, 2015

@author: mohamed265
'''
def fun(n, m):
    m -= 1
    solu = [0] * n
    l = n - 1
    po = l - 1
    o = 0
    for i in range(n):
    # print (m , pow(2, po) )
        if m >= pow(2, po):
            solu[l] = i + 1
            m -= pow(2, po)
            l -= 1
        else:
            solu[o] = i + 1
            o += 1
        po -= 1
    print(*solu)
    
def fun2(n, m):
    m -= 1
    solu = [0] * n
    l = n - 1
    po = l - 1
    o = 0
    for i in range(n - 1):
        #print (m , 1 << po)
        if m >= 1 << po:
            solu[l] = i + 1
            m -= 1 << po
            l -= 1
        else:
            solu[o] = i + 1
            o += 1
        po -= 1
    solu[o] = n
    print(*solu)

temp = [int(x) for x in input().split()]
n = temp[0]
m = temp[1]
# for i in range(1,17):
fun2(n, m)
 
        

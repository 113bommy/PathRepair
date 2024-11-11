import sys,math
'''
def opt(weight,value,n,w):
    f=[0]*(n+1)
    for i in range(n+1):
        f[i] = max(v[i]


n,w = map(int,input().split())
weight=[]
value=[]
for _ in range(n):
    W,V = map(int,input().split())
    weight.append(W)
    value.append(N)
print(opt(weight,value,n,w))
'''
def ret(n,i):
    i=str(i)
    n=str(n)
    for x in i:
        if x in n:
            return True
    return False

n = int(input())
c=0
for i in range(1,int(n**0.5)+5):
    if n%i == 0:
        if n//i == i:
            if ret(n,i):
                c+=1
                continue
        if ret(n,i):
            c+=1
        if ret(n,n//i):
            c+=1
print(c)

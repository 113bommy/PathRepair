from math import *
n,x = map(int,input().split())
a = list(map(int,input().split()))
m,y = map(int,input().split())
b =  list(map(int,input().split()))
a.reverse()
b.reverse()
#print(a,b)
res1 = 0
for  i in range(len(a)):
    res1+=int(a[i])*(x)**i
res2 = 0
for  i in range(len(b)):
    res2+=int(b[i])*(y)**i
if res1==res2:
    print('=')
    quit()
if res1<res2:
    print('<')
    quit()
print('>')
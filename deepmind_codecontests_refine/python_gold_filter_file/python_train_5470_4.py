import math,sys
def gcd(x,y):
    if y == 0:
        return x
    else:
        return gcd(y,x%y)
n = int(input())
a = list(map(int,input().split(' ')))
i = 1
if len(a)==1:
    print(0)
    print(a[0])
    sys.exit()
while i<len(a):
    if gcd(max(a[i],a[i-1]),min(a[i],a[i-1]))>1:
        a.insert(i,1)
    i+=1
print(len(a)-n)
a = map(str,a)
print(' '.join(a))

import sys
import math
class DictList(dict):
    def __setitem__(self, key, value):
        try:
            # Assumes there is a list on the key
            self[key].append(value)
        except KeyError: # If it fails, because there is no key
            super(DictList, self).__setitem__(key, value)
        except AttributeError: # If it fails because it is not a list
            super(DictList, self).__setitem__(key, [self[key], value])

def fn(n,x0,a,b):
    c=[0]*n
    d=[0]*n
    for i in range(n):
        c[i] = min(a[i],b[i])
        d[i] = max(a[i],b[i])
    cnt = 0
    dis=0
    i=0
    while(i<n):
        if cnt>3:
            return -1
        if c[i]<=x0 and x0<=d[i]:
            i=i+1
            continue
        if x0<c[i]:
            l=x0
            x0=c[i]
            dis = dis+c[i]-l
            i=0
            cnt=cnt+1
            continue
        elif x0>d[i]:
            l=x0
            x0 = d[i]
            dis = dis + l-d[i]
            i=0
            cnt=cnt+1
            continue
    return dis
if __name__ == '__main__':    
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = (data[0])
    x0 = data[1]
    z = data[2:]
    a=[]
    b=[]
    for i in range(2*n):
        if i%2==0:
            a.append(z[i])
        else:
            b.append(z[i])
    print(fn(n,x0,a,b))
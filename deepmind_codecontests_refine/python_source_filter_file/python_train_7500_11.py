import sys;

def init(n_):
    length = 1;
    while(length < n_):
        length*=2
    element=[0]*(2*length-1)
    for i in range(2*length-1):
        element[i] = 0
    return element,length

def update(k,a,element):
    k+=n-1
    element[k]+=a
    while(k > 0):
        k = (int)((k-1)/2)
        element[k] = element[k*2+1]+element[k*2+2]

def findmin(a, b):
    return findquery(a,b+1,0,0,n)

def findquery(a, b, k, l, r):
    if(r <= a or b <= l):
        return 0
    if(a <= l and r <= b):
        return element[k]

    vl = findquery(a,b,k*2+1,l,(int)((l+r)/2+0.5))
    vr = findquery(a,b,k*2+2,(int)((l+r)/2),r)
    return vl+vr

n,q = map(int, input().split());

element,n = init(n)

for i in range(q):
    query,key,value = map(int, input().split());
    if(query == 0):
        update(key-1,value,element)
    else :
        print(findmin(key-1,value))

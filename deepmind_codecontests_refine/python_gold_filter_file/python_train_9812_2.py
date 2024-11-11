# from decimal import *
# getcontext().prec=16
# from math import sqrt
# from scipy.special import binom
# from collections import defaultdict
from math import sin,pi
from copy import deepcopy

def check(a,b,c):
    liste=[[a,b,c],[b,c,a],[b,a,c]]
    for element in liste:
        a,b,c=element
        if (b[0]-a[0])*(c[0]-b[0])+(b[1]-a[1])*(c[1]-b[1])==0:
            return True
    return False
def check_square(liste):
    a,b,c=liste
    liste=[[a,b,c],[b,c,a],[b,a,c]]
    for element in liste:
        a,b,c=element
        if ( (b[0]-a[0])**2+(b[1]-a[1])**2 )==( (b[0]-c[0])**2+(b[1]-c[1])**2 ):
            return True
    return False

tempo=[0 for i in range(8)]
perm=[]
for i in range(5):
    tempo[i]=1
    for j in range(i+1,6):
        tempo[j]=1
        for k in range(j+1,7):
            tempo[k]=1
            for l in range(k+1,8):
                tempo[l]=1
                copy=deepcopy(tempo)
                perm.append(copy)
                tempo[l]=0
            tempo[k]=0
        tempo[j]=0
    tempo[i]=0

entry=[]
for i in range(8):
    x,y=list(map(int,input().split(" ")))
    entry.append((x,y))

bool=False
for permutation in perm:
    first_set=[]
    second_set=[]
    for i in range(8):
        if permutation[i]==1:
            first_set.append(entry[i])
        else:
            second_set.append(entry[i])
    a,b,c,d=first_set
    w,x,y,z=second_set
    if check(a,b,c) and check(b,c,d) and check(c,d,a):
        if check(w,x,y) and check(x,y,z) and check(y,z,w):
            if check_square(first_set[:-1]):
                bool=True
            elif check_square(second_set[:-1]):
                first_set,second_set=second_set,first_set
                bool=True
    if bool:
        break

if not bool:
    print("NO")
else:
    index_square=[]
    index_rectangle=[]
    for element in first_set:
        index_square.append(str(entry.index(element)+1))
    for element in second_set:
        index_rectangle.append(str(entry.index(element)+1))
    print('YES\n'+(" ").join(index_square)+'\n'+(' ').join(index_rectangle))
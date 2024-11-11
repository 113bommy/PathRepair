import math
import itertools
import sys
input=sys.stdin.readline

############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))

ans = 0
n = inp()
#rock scissors paper
a=inlt()
b=inlt()
c=[a[1],b[2]]
d=[a[2],b[0]]
e=[a[0],b[1]]

x=[b[0],a[1]]
y=[b[1],a[2]]
z=[b[2],a[0]]

m = itertools.permutations([(0, 0), (0, 2), (1, 1), (1, 0), (2, 2), (2, 1)])
res=9**9
'''for i in range(3):
    ans=0
    #j == alice
    for j in range(0,5,2):
        for k in range(3):
            if j==2 and k==0:
                ans+=1
            if j==1 and k==2:
                ans+=1
            if j==0 and k==1:
                ans+=1
    res=min(ans,res) '''

for val in m:
    ans=0
    array = a
    array2 = b
    f = n
    for i in range(6):
        j,k=map(int,val[i])
        '''if array[j]>0<array2[k]:
            f-=min(array[j],array2[k])
            if j==2 and k==0:
                print(min(array[j],array2[k]))
                ans+=min(array[j],array2[k])
            if j==1 and k==2:
                ans+=min(array[j],array2[k])
            if j==0 and k==1:
                ans+=min(array[j],array2[k])'''
        array[j]-=min(array[j],array2[k])
        array2[k]-=min(array[j],array2[k])

    res=min(res, min(array[0],array2[1])+min(array[1],array2[2])+min(array[2],array2[0]))
    
print(res,min(c)+min(d)+min(e))



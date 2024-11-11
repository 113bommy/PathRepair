import math
def check(a,b,k):
    sa=((k*(k+1))/2 + b- a)/2
    if(sa<0 or sa!=int(sa) or sa-(b-a)<0):
        return False
    return True

def proB(a,b):
    if(a==b):
        return 0
    i=1
    while(True):
        if(check(a,b,i)):
            return i
        i+=1
t=int(input())

for i in range(t):
    arr=list(map(int,input().split()))
    a,b=arr
    print(proB(a,b))
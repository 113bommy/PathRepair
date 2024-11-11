import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_array(): return list(map(int, sys.stdin.readline().strip().split()))
def input(): return sys.stdin.readline().strip()
#n,k = get_ints()
#Arr = get_array()
#Arr.sort()
n,a,b,k = get_ints()
h=get_array()
ans=int(0)
t=[0]*n
for i in range(n):
    md=h[i]%(a+b)
    if(md<=a and md>0):
        t[i]=0
    else:
        if(md==0):
            md=b
        else:
            md-=a
        t[i]=int((md+a-1)/a)
t.sort()
for i in range(n):
    k-=t[i]
    if(k<0):
        break
    ans+=1
print(ans)




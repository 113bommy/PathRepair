n,c=map(int,input().split())
a=[]
b=[]
for i in range(n):
    x,y=map(int,input().split())
    a.append(x)
    b.append(y)

def solve(x,f):
    cnt=n
    for i,j in zip(a,b):
        cnt+=(i*x)//j
    if f==0:
        return cnt<c
    else:
        return cnt>c

ll=0
h=10**9

while ll<h-1:
    mid=ll+(h-ll)//2
    if solve(mid,0):
        ll=mid
    else:
        h=mid-1
if solve(ll+1,0):
    ll+=1
lu=0
h=10**9

while lu<h:
    mid=lu+(h-lu)//2
    if solve(mid,1):
        h=mid
    else:
        lu=mid+1
print(lu-ll-1)

from collections import deque
def ngr(a,n):
    s=deque()
    l=[]
    
    for j in range(n-1,-1,-1):
        if len(s)==0:
            s.append(a[j])
            l.append(-1)
        else:
            while len(s)!=0 and s[len(s)-1]>=a[j]:
                s.pop()
            if len(s)==0:
                l.append(-1)
            else:
                l.append(s[len(s)-1]^a[j])
            s.append(a[j])
    # l.reverse()
    return l

def ngl(a,n):
    s=deque()
    l=[]
    
    for j in range(n):
        if len(s)==0:
            s.append(a[j])
            l.append(-1)
        else:
            while len(s)!=0 and s[len(s)-1]>=a[j]:
                s.pop()
            if len(s)==0:
                l.append(-1)
            else:
                l.append(s[len(s)-1]^a[j])
            s.append(a[j])
    return l

n=int(input())
a=list(map(int,input().split()))

c=ngr(a,n)
d=ngl(a,n)
c.extend(d)

print(max(c))
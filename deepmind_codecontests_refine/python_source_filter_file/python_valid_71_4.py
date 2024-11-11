t=int(input())
k1=[0]
for i in range(1, 11):
    for j in range(1, 11):
        e=str(i)*j
        e=int(e)
        k1.append(e)
k1=sorted(k1)
 
k2=[]
 
def ad(i, j, s):
    if len(s)==10:
        if s!=s[0]*len(s):
            k2.append(int(s))
    else:
        if s!='' and s!=s[0]*len(s):
            k2.append(int(s))
        if not (i=='0' and s==''):
            ad(i, j, s+i)
        ad(i, j, s+j)
 
for i in range(10):
    for j in range(i+1, 10):
        ad(str(i), str(j), '')

k2+=k1
k2=sorted(k2)
 
def binsearch(l, r, arr, n):
    while l+1<r:
        mid=(l+r)//2
        if arr[mid]<=n:
            l=mid
        else:
            r=mid

    if n==arr[l]:
        return l
    return r
 
for i in range(t):
    a,b=map(int, input().split())
    if b==1:
        ans=binsearch(-1, len(k1), k1, a)
        print(k1[ans])
    else:
        ans=binsearch(-1, len(k2), k2, a)
        print(k2[ans])
def sort(l):
    for i in range(len(l)-1):
        for j in range(len(l)-i-1):
            if l[j]>l[j+1]:
                l[j],l[j+1]=l[j+1],l[j]
    return l

def subset(l):
    l=sort(l)
    l.append(0)
    A=[]
    B=[]
    i=0
    while i < (len(l)-1):
        if l[i]==l[i+1]:
            A.append(l[i])
            B.append(l[i])
            i=i+1
        else:
            A.append(l[i])
        i=i+1
        a=set(A)
        b=set(B)
    return a,b

def mex(s):
    s=list(s)
    i=0
    while i<len(s):
        if s[i]!=i:
            return i
        i=i+1
    return i

case=int(input())
while case:
    n=int(input())
    lst=input().split(' ')
    for i in range(len(lst)):
        lst[i]=int(lst[i])
    A,B=subset(lst)
    print(mex(A)+mex(B))
    case=case-1
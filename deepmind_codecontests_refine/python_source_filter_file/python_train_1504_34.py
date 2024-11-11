T=int(input())
l=-100000000000
r=100000000000
while T>0:
    T-=1
    A,B,C=input().split()
    b=int(B)
    if C=='N':
        if A=='>=':
            A='<'
        elif A=='<=':
            A='>'
        elif A=='>':
            A='<='
        else:
            A='>='
    if A=='>=':
        b-=1
    if A=='<=':
        b+=1
    if A[0]=='>':
        l=max(l,b)
    else:
        r=min(r,b)
if l+1>=r:
    print('Impossible')
else:
    print(l+1)

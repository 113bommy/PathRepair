n,p=map(int,input().split())
a=list(map(int,input().split()))
gu=0
ki=0
for i in a:
    if a%2==0:
        gu+=1
    else:
        ki+=1
if ki:
    print(2**(n-1))
else:
    if p:
        print(0)
    else:
        print(2**n)

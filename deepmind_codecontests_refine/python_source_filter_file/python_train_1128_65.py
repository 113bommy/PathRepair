n=int(input())
A=list(map(int,input().split()))
C=set()
d=0
for a in A:
    c=a//400
    if c<8:C.add(c)
    else:d+=1
print(len(C),len(C)+d)
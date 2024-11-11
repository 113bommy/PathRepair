import sys
b,q,l,m=map(int,input().split())
seq=set(map(int,input().split()))
x=0
for i in range(100) :
    if abs(b)>l :
        break
    if b not in seq :
        x+=1
    b*=q

    if x>100 :
        print("inf")
        sys.exit()

print(x)

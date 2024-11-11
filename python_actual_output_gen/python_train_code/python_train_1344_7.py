r1,c1,r2,c2=map(int,input().split())
if r1==r2 or c1==c2:
    print(1,end=" ")
else:
    print(2,end=" ")
if (r1+c1)%2 != (r2+c2)%2 :
    print(0,end=" ")
else:
    if r1+c1 == r2+c2 or abs(r1-c1)==abs(r2-c2):
        print(1,end=" ")
    else:
        print(2,end=" ")
print(max(abs(r1-r2),abs(c1-c2)))
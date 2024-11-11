a,b=map(int,input().split())
l=list(map(int,input().split()))
l.sort()
c=0
for i in l:
    if b!=0:
        if i<0:
            c+=(-i)
            b-=1
        else:
            break
    else:
        break
print(c)
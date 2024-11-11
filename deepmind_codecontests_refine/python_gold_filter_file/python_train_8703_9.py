l,r,x,y,k=map(int,input().split())
aa=[int(i) for i in range(l,r+1)]
bb=[int(i) for i in range(x,y+1)]
kek1=0
kek2=0
c=False
while kek1<r-l+1 and kek2<y-x+1:
    if aa[kek1]/bb[kek2]>k:
        kek2+=1
    elif aa[kek1]/bb[kek2]<k:
        kek1+=1
    else:
        c=True
        break
print("YES" if c else "NO")
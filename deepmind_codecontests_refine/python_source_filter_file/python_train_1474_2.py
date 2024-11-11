I=lambda: list(map(int,input().split()))
n,=I()
l=I()
ar=[0]*200001
fl=1
for i in l:
    ar[i]+=1
    if ar[i]>2:
        print("NO")
        fl=0
        break
if fl:
    print("YES")
    inc=[]
    dec=[]
    for i in range(len(ar)):
        if ar[i]:
            if ar[i]==1:
                inc.append(i)
            else:
                inc.append(i)
                dec.append(i)
    print(len(inc))
    print(*inc)
    print(len(dec))
    print(*dec)
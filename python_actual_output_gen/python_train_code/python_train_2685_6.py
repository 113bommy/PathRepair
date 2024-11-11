k=int(input())
l=list(map(int,input().split()))
l.sort()
l=l[::-1]
s=0
v=0
if(k==0):
    print(0)
else:
    for i in range(12):
        if s>=k:
            print(i)
            v=1
            break
        s+=l[i]
    if(v==0):
        print(12)
    if(k>s):
        print(-1)

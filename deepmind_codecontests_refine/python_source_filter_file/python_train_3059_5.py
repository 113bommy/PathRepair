x=int(input())
if(x==2):
    print(1)
else:
    x-=1
    cnt=0
    for i in range(1,x):
        ok=0
        for j in range(2,i-1):
            if(x%j==0 and i%j==0): ok=1
        if(ok==0) :cnt+=1
    print(cnt)

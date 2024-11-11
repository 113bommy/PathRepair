n=int(input())
a=[int(i) for i in input().split()]
gri=a[:(n//2)]
adr=a[(n//2):]
print(gri,adr)
if n==1:
    print(-1)
else:
    if sum(gri)!=sum(adr):
        print(len(gri))
        for i in range(len(gri)):
            print(i+1,end=' ')
    else:
        if n==2:
            print(-1)
        if n==3:
            print(2)
            print("0 2")
            #for i in range(2):
                # print(
        else:
            t=len(gri)
            print(t)
            for i in range(len(gri[:t-1])):
                print(i+1,end=' ')
            
        

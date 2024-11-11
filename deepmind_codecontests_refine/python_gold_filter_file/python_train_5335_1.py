t=int(input())
for _ in range(t):
    n=int(input())
    arr=list(map(int,input().split()))
    l=1
    r=n-1
    a=arr[0]
    b=0
    i=1
    p=a
    if n<=2:
        if n==1:
            print(1,arr[0],0)
        else:
            print(2,arr[0],arr[1])
    else:
        while l<r:
            # print("previous",p)
            if i % 2==1:
                # print("bob")
                s=0
                while s<p+1:
                    if l<=r:
                        s+=arr[r]
                        r-=1
                    else:
                        break
                b+=s
                # print("BOB ATE",s,)
            else:
                # print("ALICE")
                s=0
                while s <p+1:
                    # print("ALICE",s,p+1)
                    if l<=r:
                        s+=arr[l]
                        l+=1
                    else:
                        break
                a+=s
                # print("ALICE ATE",s,)
                # print(l,r)

            p=s
            i+=1
            # print(i,s,p)
            # print("SUM",a,b)
            # print(i,a,b)
        if a+b<sum(arr):
            if i%2==0:
                print(i+1,a+arr[l],b)
            else:
                print(i+1,a,b+arr[l])
        else:
            print(i,a,b)



n,vb,vs=map(int,input().split())
arr=list(map(int,input().split()))
x,y=map(int,input().split())

if(vs>vb):
    print(2)
else:
    i=1
    mx=10**9+7
    indx=0
    while(i<n):

        if(arr[i]==x):
            print(i+1)
            break
        else:
            time=(arr[i]/vb)+(((x-arr[i])**2+y**2)**.5)/vs
            if(mx>time):
                mx=time
                indx=i+1
            else:
                print(indx)
                break

        i+=1
        if(i==n):
            print(i)




# it was stupid to think using brute intuitions, like pick first or last greedily,
# greddy must follow observation, so you also had the observation that have to do it from last
# instead you picked in random all order, those greedy after thought solutions never work!,its not cp
n=int(input())
if n==1 or n%2==0:
    # print("ghe")
    print(-1)
#     exit(0)

a=list(map(int,input().split(' ')))
# so the last element, has to be made 0, greedily, first, so by induction, it has proof, 
a=[0]+a
# this is very ine elegant implementation
ans=0
for j in range(n,0,-1):
    if j%2==1:
        i=(j-1)//2
        ans+=a[2*i+1]
        mina=min(a[i],a[2*i],a[2*i+1])
        a[i],a[2*i],a[2*i+1]=a[i]-mina,a[2*i]-mina,a[2*i+1]-mina    
        if a[2*i+1]>0:
            nonzero=0
            if a[i]>0:
                a[i]=max(0,a[i]-a[2*i+1])
            else:
                a[2*i]=max(0,a[2*i]-a[2*i+1])
            a[2*i+1]=0
    else:
        i=(j)//2
        if 2*i+1>n:
            # print("hemlo")
            print(-1)
            exit(0)
        ans+=a[2*i]
        mina=min(a[i],a[2*i],a[2*i+1])
        a[i],a[2*i],a[2*i+1]=a[i]-mina,a[2*i]-mina,a[2*i+1]-mina    
        if a[2*i]>0:
            a[i]=max(0,a[i]-a[2*i])
            a[2*i]=0
# print(a)/
if any(a):
    print(-1)
else:
    print(ans)

        
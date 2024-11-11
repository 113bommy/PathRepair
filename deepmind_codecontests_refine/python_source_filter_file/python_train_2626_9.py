t=int(input())
for i in range(0,t):
    n,p,k=[int(x) for x in input().split()]
    a=[int(x) for x in input().split()]
    a.sort()
    rem=p
    j=0
    ans1=0
    maxadded=0
    
    for j in range(1,n,2):
        temp=a[j]
        if rem>=temp:
            rem-=temp
            ans1+=2
            maxadded=j
        else:
            break
    if maxadded+1<n:
        if rem>=a[maxadded+1]:
            ans1+=1
    ans2=0
    rem=p
    # print("Hi")
    # print(ans1)
    # print("Yo")
    if maxadded==(n-1):
        print(ans1)
    else:
        j=maxadded+1
        # print("andar")
        # print(maxadded+1)
        while(j>=0):
            temp=a[j]
            if rem>=temp:
                rem-=temp
                if j!=0:
                    ans2+=2
                else:
                    ans2+=1
                minadded=j
                # print(rem,j)
                j-=2
            else:
                break
        print(max(ans2,ans1))
        
    
        
    
    # while(j<n):
    #     temp=a[j+1]
    #     maxadded=j+1
    #     if rem>=temp:
    #         ans1+=2
    #         j+=2
    #         rem=rem-temp
    #     else:
    #         break
    # if rem==0:
    #     print(ans1)
    # else:
    #     start=maxadded+1
    #     j=start
    #     rem2=p
    #     ans2=0
    #     while(j>=0):
    #         temp=a[j]
    #         if rem2>=temp:
    #             rem2=rem2-temp
    #             j-=2
    #             ans2+=2
    #             minadded=j
    #         else:
    #             break
    #     print(max(ans1,ans2))
    
        
        
        
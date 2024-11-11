from collections import defaultdict as dc
n=int(input())
a=list(map(int,input().split()))
m=dc(int)
for i in range(n):
    m[a[i]]+=1
if(m[0]>=2 or m[0]==n):
    print("cslnb")
else:
    flag=0
    for i in range(n):
        if(m[a[i]]>2 or (m[a[i]]==2 and m[a[i]-1]>0)):
            flag=1
            break
    if(flag):
        print("cslnb")
    else:
        cnt=0
        for i in range(n):
            if(m[a[i]]==2):
                cnt+=1
        if(cnt>1):
            print("cslnb")
        else:
            ans=0
            a.sort()
            for i in range(n):
                if(a[i]>i):
                    ans+=a[i]-i
            if(ans%2):
                print("sjfnb")
            else:
                print('cslnb')
        



        

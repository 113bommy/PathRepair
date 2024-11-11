n,m,a,b,k=map(int,input().split())
arr=[]
brr=[]
arr=list(map(int,input().split()))
brr=list(map(int,input().split()))
t=min(n,m)
# print(t)
q=-1
if t<=k:
    print(q)
    exit()
x=arr[k]+a
y=brr[m-1]
if x>y:
    print(q)
    exit()
else:
    crr=[]
    ind=0
    for i in range(1,k+1):
        u=arr[i]+a
        for j in range(ind,len(brr)):
            v=k-i
            # print(v,j)
            if brr[j]>=u:
                ind=j
                if v>=(len(brr)-j):
                    print(q)
                    exit()
                else:
                    crr.append(j+v)
                    break
            
    # for i in range(k,0,-1):
        
    #     u=arr[i]+a
    #     # print(i,u)
    #     for j in range(0,len(brr)):
    #         v=k-i
    #         # print(v,j)
    #         if brr[j]>=u:
    #             if v>=(len(brr)-j):
    #                 print(q)
    #                 exit()
    #             else:
    #                 crr.append(j+v)
    #                 break
z=max(crr)
# print(crr)
print(brr[z]+b)
n=int(input())
arr1=list(map(int,input().split()))
arr2=list(map(int,input().split()))

arr3=[0]
mini=n+1
for i in range(0,len(arr2)):
    if arr2[i]<mini and arr2[i]!=0:
        mini=arr2[i]
if mini==n+1:
    print(len(arr1))
    exit()
q=n+1
a=0
b=0
m=0
for i in range(0,len(arr2)):
    if mini==arr2[i]:
        q=int(i)
    if arr2[i]!=0:
        # a=q+arr2[i]
        # b=i+1
        m=max(i+1-arr2[i]+1,m)
        # if (i+1)>=:
        #     arr3.append(b-a)
            # print(arr3)

c=1
count=0
# print(m)
# x1=max(arr3)
# print(q)
if arr2[q]==1:    
    for i in range(q+1,len(arr2)):
        c+=1
        if arr2[i]==c:
            count+=1
        else:
            break


    
    a1=0
    b1=0
    # print(count)
    if count==len(arr2)-q-1:
        for j in range(0,q):
            if arr2[j]!=0:
                # a1=arr2[i]-arr2[count+q]-1
                # b1=i+1
                if arr2[j]<=(arr2[count+q]+1+j):
                    # print('hi')
                    print(m+n)
                    exit()
        print(q)
        exit()
    print(m+n)
    exit()
# if (q+1+x1+n)==2335:
#     print(2334)
#     exit()
# print("hi")
print(m+n)
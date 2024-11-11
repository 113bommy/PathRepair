n=int(input())
ma=float("inf")
arr=[]
p=[]
x=-1
for i in range(n):
    a,b,c,d = map(int,input().split())
    arr.append([a,b,c])
    p.append(d)
    # print(sum(arr[i]))
    if a+b+c>ma:
        ma=a+b+c
        x=i
for i in range(n-1):
    for j in range(i+1,n):
        # print(i,j)
        if arr[i][0]<arr[j][0] and arr[i][1]<arr[j][1] and arr[i][2]<arr[j][2]:
            # print(arr[i][0],arr[j][0],arr[i][0]<arr[j][0] and arr[i][1]<arr[j][1] and arr[i][2]<arr[j][2])
            # print("out",i,j)
            p[i]=float("inf")
        if arr[j][0]<arr[i][0] and arr[j][1]<arr[i][1] and arr[j][2]<arr[i][2]:
            print(arr[i][0],arr[j][0],arr[i][0]<arr[j][0] and arr[i][1]<arr[j][1] and arr[i][2]<arr[j][2])
            # print("out",i,j)
            p[j]=float("inf")

# print(arr,x,p)
print(p.index(min(p))+1)
n=int(input())
arr=[]
for i in range(n):
    arr.append(int(input()))
c=0
for i in range(n):
    if arr[i]%2==1:
        c+=1


for i in range (n):
    if c//2>0 and arr[i]%2==1:
        print(arr[i]//2+1)
        c-=1
    else:
        print(arr[i]//2)
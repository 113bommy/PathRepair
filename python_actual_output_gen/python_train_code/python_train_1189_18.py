n,k=map(int,input().split())
s=input()
arr=list(s)
if(arr[0]!='1' and k>0):
    arr[0]="1"
    k-=1
for i in range(1,n):
    if(arr[i]!="0" and k>0):
        arr[i]="0"
        k-=1
if(n==1 and k==1):
    print(0)
else:
    print("".join(arr))
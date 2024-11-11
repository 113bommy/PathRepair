n=int(input())
arr=list(map(int,input().split()))
brr=input()
l=-10**9
r=10**9
for i in range(4,n):
    if brr[i-1] ==brr[i-2] ==brr[i-3] ==brr[i-4] !=brr[i]:
        if brr[i] =='1':
            l=max(l,arr[i],arr[i-1],arr[i-2],arr[i-3],arr[i-4]) +1
        else:
            r=min(r,arr[i],arr[i-1],arr[i-2],arr[i-3],arr[i-4]) -1
print(l,r)
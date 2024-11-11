n,d = map(int, input().split())
s=input()
arr=[]
cnt=0
for i in range(n):
    arr.append(int(s.split(' ')[i]))
i=1
j=0
while i!=n:
    if arr[j]<arr[i]:
        i+=1
        j+=1
    elif arr[j]==arr[i]:
        cnt+=1
        arr[i]+=d
        i+=1
        j+=1
    elif arr[j]>arr[i]:
        k=arr[j]-arr[i]
        if k<d:
            if 2*k==d:
                cnt+=2
                arr[i]+=2*d
            else:
                cnt+=1
                arr[i]+=d
        else:
            if k%d>0:
                k=(k//d)+1
                cnt+=k
                arr[i]+=d*k
            else:
                k=(k//d)+1
                cnt+=k
                arr[i]+=d*k
        i+=1
        j+=1
print(cnt)
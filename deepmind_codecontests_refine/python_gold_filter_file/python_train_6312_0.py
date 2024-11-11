
mod=10**9+7
num1,num2=map(int,input().split())
if num2%num1:
	print("0")
else:
    num2=num2//num1
    arr=set()
    for i in range(1,int(pow(num2,0.5)+1)):
        if num2%i==0:
            arr.add(i)
            arr.add(num2//i)
    arr=sorted(list(arr))
    cop2=arr[::]
    for i in range(len(cop2)):
        cop2[i]=pow(2,arr[i]-1,mod)
        for j in range(i):
            if arr[i]%arr[j]==0:
                cop2[i]-=cop2[j]
    print(cop2[-1]%mod)


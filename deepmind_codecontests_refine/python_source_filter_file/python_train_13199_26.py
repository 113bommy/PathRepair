N=int(input())
ans=[]
for i in range(1,int(N**.5)):
    if N%i==0:
        ans.append(N//i+i-2)
print(min(ans))
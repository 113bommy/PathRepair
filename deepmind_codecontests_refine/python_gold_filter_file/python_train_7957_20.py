s=input()
n=int(input())
val=list(map(int,input().split()))

ans=0
arr=[]
for i in range(len(s)):
    ans+=(val[ord(s[i])-97]*(i+1))
arr=max(val)

# print(arr,ans)
for j in range(n):
    ans+=arr*(j+i+2)
    # print(arr,j+i+2)
print(ans)
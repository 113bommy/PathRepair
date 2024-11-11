n=int(input())
nums=list(map(int,input().split()))
mini=float('inf')
for i in range(n-1):
    if abs(nums[i]-nums[i+1])<mini:
        mini=abs(nums[i]-nums[i+1])
        ans=[i+1,i+2]

if abs(nums[0]-nums[-1])<mini:
    ans=[n,1]

print(ans)


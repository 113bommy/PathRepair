# import math
# n=int(input())
# arr=list(map(int,input().split()))
# p=math.pi
# arr.sort(reverse=True)
# ans=0
# if n==1:
#     print(math.pi*(arr[0]**2))
# else:
#     if n%2==1:
#         for i in range(0,n,2):
#             ans+=(arr[i]**2)-(arr[i+1])**2
#         ans+=arr[n-1]**2
#     else:
#         for i in range(0,n+1,2):
#             ans+=(arr[i]**2)-(arr[i+1])**2
#     print(ans*p)

import math
n=int(input())
arr=list(map(int,input().split()))
p=math.pi
arr.sort()
ans=0
if n%2==1:
    for i in range(0,n,2):
        if i>=2:
            ans+=arr[i]**2-arr[i-1]**2
        else:
            ans+=arr[i]
else:
    for i in range(1,n,2):
        ans+=((arr[i]**2)-(arr[i-1]**2))
        # print(ans)
print(ans*p)
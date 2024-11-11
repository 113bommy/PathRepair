#code
# def helpp(i,j,arr):
#     tot=0
#     for val,ind in enumerate(arr[i+1:j-1]):
#         if arr[ind-1]<val and val<arr[ind-1]:
#             tot+=1
#     return tot
    
t=int(input())
dp=[0,0,0]

for i in range(3,5*10**5,2):
    dp.append(dp[i-2]+ 4*(i-2)*(i//2) +4*(i//2) )
    dp.append(0)
# print(dp)

while t>0:
    t-=1
    n=int(input())
    print(dp[n])
n=int(input())
arr=[]
for i in range(n):
    arr.append(list(map(int,input().split())))
ans=[0]*n
ans[0]=int(((arr[0][1]*arr[0][2])//arr[1][2])**0.5)
# print(ans)
for i in range(1,n):
    ans[i]=arr[0][i]//ans[0]
print(ans)
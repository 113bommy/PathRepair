n=int(input())
a =[int(input()) for i in range(n)]
res = [[a[i],i]for i in range(n)]
res.sort()
ret =0
for i in range(n):
    if res[i][1]%2 != i%2:ret+=1
print(ret/2)

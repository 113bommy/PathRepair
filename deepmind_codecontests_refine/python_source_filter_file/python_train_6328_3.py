n=int(input())
l=[[0]*10for _ in range(10)]
for x in range(1,n+1):l[a=int(str(x)[0])][b=int(str(x)[-1])]+=1
print(sum(l[i][j]*l[j][i]for i in range(10)for j in range(10)))
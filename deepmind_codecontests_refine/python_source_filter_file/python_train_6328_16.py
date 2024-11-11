n=int(input())
ans=-1
c=[[0]*10for i in range(10)]
for i in range(n):c[int(str(i)[0])-1][int(str(i)[-1])-1]+=1
for i in range(10):
 for j in range(10):ans+=c[i][j]*c[j][i]
print(ans)
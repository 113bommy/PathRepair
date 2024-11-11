n=int(input())

c=[[0]*10 for _ in range(10)]
ans=0
for i in range(1,n):
    c[int(str(i)[0])][int(str(i)[-1])] +=1
    
    
for i in range(10):
    for j in range(10):
        ans += c[i][j] * c[j][i]
    
print(ans)
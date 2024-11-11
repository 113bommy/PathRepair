n=int(input())

c=[[0]*10 for i in range(10)]

for i in range(1,n+1):
    t=str(i)
    c[int(t[0])][int(t[-1])]+=1
    
ans=0
for i in range(10):
    for j in range(10):
        ans+=c[i][j]*c[j][i]
        
print(ans)
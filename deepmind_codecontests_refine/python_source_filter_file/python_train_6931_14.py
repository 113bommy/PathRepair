n = int(input())
p = [1]*(n+2)
if n<2:
    print(1)
else:
    print(2)
for i in range(2,n+2):
    if p[i]==1:
        for j in range(2,((n+1)//i)+1):
            p[i*j]=2
    
print(*p[2:n+2])
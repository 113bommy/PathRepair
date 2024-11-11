l=[]
n=int(input())
for k in range(n):
    l.append(input())
count=0
for i in range(1,n-1):
    if 'x' in l[i]:
        for j in range(1,n-1):
            if ('x' in l[i][j])and('x' in l[i-1][j-1])and('x' in l[i-1][j+1])and('x' in l[i+1][j+1])and('x' in l[i+1][j-1]):
                count+=1
print(count)
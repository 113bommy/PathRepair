n=int(input())
mat=[]
count=0
i=0
while i<n:
    mat.append([])
    i += 1
for i in range(n):
    inputs=input()
    for ch in inputs:
        mat[i].append(ch)
for i in range(1,n-1):
    for j in range(1,n-1):
        if mat[i][j]=='x':
            if mat[i-1][j-1]=='x' and mat[i-1][j+1]=='x' and mat[i+1][j-1]=='x' and mat[i+1][j+1]=='x':
                count += 1
print(count)
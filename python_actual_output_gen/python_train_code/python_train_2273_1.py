z=[];a=int(input());s=0
for _ in " "*a:z+=[input()]
for i in range(1,a-1):
    for j in range(1,a-1):
        if z[i-1][j-1]==z[i-1][j+1]==z[i+1][j+1]==z[i+1][j-1]== 'X' :s+=1
print(s)
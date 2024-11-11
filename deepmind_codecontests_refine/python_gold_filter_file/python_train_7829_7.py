mat=[]
for _ in range(3):
    s=input()
    l=[]
    l.append(s[0])
    l.append(s[1])
    l.append(s[2])
    mat.append(l)
#print(mat)
if(mat[0][1]==mat[2][1] and mat[1][0]==mat[1][2] and mat[0][0]==mat[2][2] and mat[0][2]==mat[2][0]):
    print("YES")
else:
    print('NO')
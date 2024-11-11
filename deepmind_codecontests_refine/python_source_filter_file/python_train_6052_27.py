ch=str(input())
def check(n):
    if n=='1':
        for i in range(4):
            for j in range(3):
                if L[i][j]==L[i][j+1] and L[i][j+1]=='0':
                    L[i][j]="1"
                    L[i][j+1]="1"
                    print(i+1,j+1,sep=" ")
                    return 0
    if n=='0':
        for j in range(4):
            for i in range(3):
                if L[i][j]==L[i+1][j] and L[i+1][j]=='0':
                    L[i][j]="1"
                    L[i+1][j]="1"
                    print(i+1,j+1,sep=" ")
                    return 0
                    
        
        
    
L=[['0','0','0','0'],['0','0','0','0'],['0','0','0','0'],['0','0','0','0']]
def delete():
    for i in range(4):
        if (L[i][0]+L[i][1]+L[i][2]+L[i][3])=="1111":
            for j in range(4):
                L[i][j]=="0"
    for i in range(4):
        if (L[0][i]+L[1][i]+L[2][i]+L[3][i])=="1111":
            for j in range(4):
                L[j][i]=="0"
for n in ch:
    check(n)
    delete()
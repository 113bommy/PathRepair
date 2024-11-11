import math

def solve():


    m=int(input())
    mat=[]
    for i in range(2):
        mat.append(list(map(int,input().split())))

    prefix1=[0 for i in range(m)]
    prefix2=[0 for j in range(m)]
    row1=mat[0][0]
    prefix1[0]=mat[0][0]
    row2=mat[1][0]
    prefix2[0]=mat[1][0]
    for i in range(1,m):
        prefix1[i]=prefix1[i-1]+mat[0][i]
        prefix2[i]=prefix2[i-1]+mat[1][i]
        row1+=mat[0][i]
        row2+=mat[1][i]

    ans=10**15
    for i in range(m):
        temp1=0
        if i!=0:
            temp1=prefix2[i-1]

        temp2=row1-prefix1[i]
        ans=min(ans,max(temp1,temp2))


    return ans





t=int(input())
for i in range(t):
    print(solve())
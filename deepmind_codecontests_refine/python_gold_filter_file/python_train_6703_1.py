def solve(x,y):
    z=0
    while not x%y and x!=0:
        z+=1
        x=x//y
    return z
def main():
    n=int(input())
    m_2=[list(map(int,input().split())) for _ in range(n)]
    m_5=[[0 for _ in range(n)] for _ in range(n)]
    x=(-1,-1)
    for i in range(n):
        for j in range(n):
            if m_2[i][j]==0:
                x=(i,j)
                break
        if x[0]!=-1:
            break
    m_2[0][0],m_5[0][0]=solve(m_2[0][0],2),solve(m_2[0][0],5)
    for i in range(1,n):
        m_5[0][i],m_2[0][i]=m_5[0][i-1]+solve(m_2[0][i],5),m_2[0][i-1]+solve(m_2[0][i],2)
        m_5[i][0],m_2[i][0]=m_5[i-1][0]+solve(m_2[i][0],5),m_2[i-1][0]+solve(m_2[i][0],2)
    for i in range(1,n):
        for j in range(1,n):
            m_5[i][j]=min(m_5[i-1][j],m_5[i][j-1])+solve(m_2[i][j],5)
            m_2[i][j]=min(m_2[i-1][j],m_2[i][j-1])+solve(m_2[i][j],2)
    if min(m_5[-1][-1],m_2[-1][-1])>1 and x[0]!=-1:
        print(1)
        print("R"*(x[1])+"D"*(n-1)+"R"*(n-x[1]-1))
    else:
        global c
        if m_5[-1][-1]<m_2[-1][-1]:
            c=m_5
        else:
            c=m_2
        b,i,j=[],n-1,n-1
        while i or j:
            if i-1>=0 and j-1>=0:
                if c[i-1][j]<c[i][j-1]:
                    b.append("D")
                    i-=1
                else:
                    b.append("R")
                    j-=1
            elif i==0:
                b.append("R")
                j-=1
            else:
                b.append("D")
                i-=1
        print(c[-1][-1])
        b.reverse()
        print("".join(b))
main()
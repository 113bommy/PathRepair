def main():
    t=int(input())
    while(t>0):
        n=int(input())
        li1=[0]*n
        li=list(map(int,input()))
        mat=[]
        for i in range(n):
            lih=[]
            for j in range(n):
                if(i==j):
                    lih.append("X")
                else:
                    lih.append("=")
                    li1[i] = li1[i]+1
            mat.append(lih)
        totfound = 1
        for i in range(n):
            if(li[i]==1):
                pass
            else:
                found = 0
                for j in range(n):
                    if((li1[j]-1)>=0 and i!=j and li[j]!=1):
                        if(mat[j].count("+")==1 and li[j]==2):
                            seti = 1
                        else:
                            found = 1
                            mat[i][j] = "+"
                            li1[j] = li1[j] - 1
                            mat[j][i] = "-"
                            li1[i] = li1[i] + 1
                if(found==0):
                    totfound = 0
                    break
#             print(mat)
        if(totfound==0):
            print("NO")
        else:
            print("YES")
            for i in range(n):
                for j in range(n):
                    print(mat[i][j],end="")
                print()
        t-=1
main()
def main():
    for _ in range(int(input())):
        n=int(input())
        mat=[]
        for _ in range(n):
            row=input()
            mat.append(row)
        fly=False
        print(mat)
        for i in range(len(mat)):
            for j in range(len(mat[i])):
                #print(mat[i][j],end=' ')
                if((mat[i][j]=='1' and (i==len(mat)-1 or j==len(mat[i])-1 or mat[i][j+1]=='1' or mat[i+1][j]=='1')) or mat[i][j]=='0'):
                    continue
                else:
                    fly=True
                    break
            if(fly):
                break
            #print('')
        if(fly):
            print("NO")
        else:
            print("YES")
if __name__=="__main__":
    main()
                
                

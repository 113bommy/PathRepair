for _ in range(int(input())):
    n=int(input())
    s=input()
    if 0<s.count("2")<2:
        print("NO")
    else:
        print("YES")
        ans=[['=']*n for i in range(n)]

        for i in range(n):
            f=1
            for j in range(n):
                if i==j:
                    ans[i][j]="X"
                else:
                    if s[i]=="2" and s[j]=="2" and f==1 and ans[i][j]=="=":
                        ans[i][j]='+'
                        ans[j][i]='-'
                        f=0
        for j in ans:
            print("".join(map(str,j)))

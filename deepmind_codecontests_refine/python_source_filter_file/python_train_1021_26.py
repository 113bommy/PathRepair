H,W=map(int,input().split())
S=["."*W]+["."+input()+"." for i in range(H)]+["."*W]
for i in range(1,H+1):
    for j in range(1,W+1):
        if S[i][j]=="#":
            if S[i+1][j]=="." and S[i-1][j]=="." and S[i][j-1]=="." and S[i][j+1]==".":
                print("No")
                exit()
print("Yes")
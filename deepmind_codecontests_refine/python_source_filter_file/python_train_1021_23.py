h,w=map(int, input().split())
S=["."+input()+"." for _ in range(h)]
S = ["."*(w+2)]+S+["."*(w+2)]
# print(S)
flag=True
for i in range(h):
    for j in range(w):
        if S[i][j]=="#":
            if S[i-1][j]=="." and S[i+1][j]=="." and S[i][j-1]=="." and S[i][j+1]==".":
                flag=False
print("Yes" if flag else "No")a
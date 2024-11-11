H, W = map(int, input().split())
s = []
for _ in range(H):
    s += [list(input())]

ls = [[0]*W for _ in range(H)]
ls[0][0] = int(bool(s[0][0]=="#"))

for i in range(1,W):
    ls[0][i] = ls[0][i-1]+ int(bool(s[0][i]=="." and s[0][i-1]=="#"))
    
for j in range(1,H):
    ls[j][0] = ls[j-1][0]+ int(bool(s[j][0]=="." and s[j-1][0]=="#"))

for i in range(1,W):
    for j in range(1,H):
        ls[j][i] = min(ls[j][i-1]+ int(bool(s[j][i]=="." and s[j][i-1]=="#")),
                       ls[j-1][i]+ int(bool(s[j][i]=="." and s[j-1][i]=="#")))
        
print(ls[-1][-1])

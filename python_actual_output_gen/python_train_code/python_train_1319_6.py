s,o =[int(i) for i in input().split()]
g=[]
for i in range(s):
    g.append(list(input()))
p=g
for i in range(s):
    for j in range(o):
        if p[i][j]==".":
            p[i][j]="D"
        if g[i][j]=="S" and  ((j<o-1 and g[i][j+1]=="W") or i<s-1 and g[i+1][j]=="W" or i<s-1 and  g[i-1][j]=="W" or j<o-1 and g[i][j-1]=="W"):
           print("No")
           exit()

print("Yes")
for i in range(s):
    for j in range(o):
        print(p[i][j],end="")
    print()
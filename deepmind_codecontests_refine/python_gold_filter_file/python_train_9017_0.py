from sys import stdin
s=stdin.readline().strip()
mt=[[False for i in range(300)] for j in range(300)]
i=150
j=150
flag=True
mt[150][150]=True;
for k in range(len(s)):
    i1,j1=i,j
    if s[k]=="L":
        i-=1
    elif s[k]=="R":
        i+=1
    elif s[k]=="U":
        j+=1
    else:
        j-=1
    if mt[i][j]==True:
        flag=False
        break
    mt[i][j]=True
    if (i1!=(i+1) or j1!=(j)) and mt[i+1][j]:
        flag=False
        break
    if (i1!=(i-1) or j1!=(j)) and mt[i-1][j]:
        flag=False
        break
    if (i1!=(i) or j1!=(j+1)) and mt[i][1+j]:
        flag=False
        break
    if (i1!=(i) or j1!=(j-1)) and mt[i][j-1]:
        flag=False
        break

if flag:
    print("OK")
else:
    print("BUG")

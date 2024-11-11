
def checkwinning(a):
    for j in range(4):
        for i in range(2):
            xc = sum([a[u][j] == "x"  for u in range(i,i+3)])
            dotc = sum([a[u][j] =="." for u in range(i,i+3)])
            if (xc == 2 and dotc ==1):
                return True

    for i in range(4):
        for j in range(2):
            xc = sum([a[i][u] == "x"  for u in range(j,j+3)])
            dotc = sum([a[i][j] =="." for u in range(j,j+3)])
            if (xc == 2 and dotc ==1):
                return True
    
    for i in range(2):
        for j in range(2):
            xc = sum([a[i+k][j+k] == "x" for k in range(3)])
            dotc =sum([a[i+k][j+k] == "." for k in range(3)])
            if (xc == 2 and dotc ==1):
                return True

    for i in range(2):
        for j in range(2,4):
            xc = sum([a[i+k][j-k] == "x" for k in range(3)])
            dotc =sum([a[i+k][j-k] == "." for k in range(3)])
            if (xc == 2 and dotc ==1):
                return True



if __name__ == "__main__":
    a=[]
    for i in range(4):
        a.append((list(input().strip())))
    if(checkwinning(a)):
        print("YES")
    else:
        print("NO")

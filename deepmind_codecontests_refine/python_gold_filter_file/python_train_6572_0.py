def answer():
    n = int(input())
    c=[]
    i=0
    while i<n:
        c.append(list(input()))
        i+=1
    i=1
    ans=0
    while i<len(c)-1:
        j=1
        while j<len(c)-1:
            if c[i][j]=="X":
                if c[i-1][j+1]=="X" and c[i+1][j+1]=="X" and c[i-1][j-1]=="X" and c[i+1][j-1]=="X":
                    ans+=1
            j+=1
        i+=1
    print(ans)
answer()
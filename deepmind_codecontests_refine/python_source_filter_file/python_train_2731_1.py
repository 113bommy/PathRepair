t=int(input())
for x in range(t):
    l=[]
    for y in range(9):
        s=input()
        m=[]
        for k in s:
            m.append(int(k))
        l.append(m)
    i=0
    j=0
    while i<9:
        if l[i][j]=='9':
            l[i][j]=1
        else:
            l[i][j]=l[i][j]+1
        i=i+1
        z=j+3
        if(z==8):
            j=8
        else:    
            j=z%8
        #print(i,j)
        
    for y in range(9):
        for k in range(9):
            print(l[y][k],end="")
        print()

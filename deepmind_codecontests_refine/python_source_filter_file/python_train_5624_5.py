def levenshtein(X,Y):
    f=[[0 for i in range(len(Y)+1)]for j in range(len(X)+1)]
    for i in range(len(X)+1):
        f[i][0]=i
    for j in range(len(Y)+1):
        f[0][j]=j
    for i in range(len(X)+1):
        for j in range(len(Y)+1):
            if X[i-1]==Y[j-1]:
                f[i][j]=min(f[i-1][j]+1,f[i][j-1]+1,f[i-1][j-1])
            else:
                f[i][j]=min(f[i-1][j]+1,f[i][j-1]+1,f[i-1][j-1]+1)
    return f[len(X)][len(Y)]

X=input()
Y=input()

print(levenshtein(X,Y))

s1=input()
s2=input()
ls1=len(s1)
ls2=len(s2)
f=[[0 for j in range(ls2+1)] for i in range(ls1+1)]
for i in range(ls1+1):
    f[i][0]=i
for i in range(ls2+1):
    f[0][i]=i
for i in range(1,ls1+1):
    for j in range(1,ls2+1):
        if s1[i-1]!=s2[j-1]:
            f[i][j]=min(f[i-1][j]+1,f[i][j-1]+1,f[i-1][j-1]+1)
        else:
            f[i][j]=f[i-1][j-1]
print(f)


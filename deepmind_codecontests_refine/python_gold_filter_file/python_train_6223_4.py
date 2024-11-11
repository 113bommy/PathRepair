S,T=input(),input()
res=n=len(T)
m=len(S)
for i in range(m-n+1):
    c = 0
    for k in range(n):
        if S[i+k]!=T[k]:
            c+=1
    res=min(res,c)
print(res)
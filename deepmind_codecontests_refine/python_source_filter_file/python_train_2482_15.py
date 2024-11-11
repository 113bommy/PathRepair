S=input()
T=input()
n=len(S)
m=len(T)

for i in range(n-m+1,-1,-1) :
    x=S[i:i+m]
    for j in range(m+1):
        if j==m :
            print((S[:i]+T+S[i+m:]).replace("?","a"))
            exit()
        if x[j]=="?" :
            continue
        elif x[j]!=T[j] :
            break
 
print("UNRESTORABLE")
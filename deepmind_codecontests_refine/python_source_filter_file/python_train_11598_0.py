S=input()
v=0
v1=0
c=0
for i in range(len(S)) :
    if S[i]=='1' :
        if v1>1 :
            v1=0
            v=1
        else :
            v=v+1
            
    else :
        if v==0 or v1>=2 or S[i]!='4' :
            c=1
            break
        else :
            v1=v1+1
if c==0 :
    print('YES')
else :
    print('NO')
            
            

n=int(input())
S=input()
l=[]
l1=[]
l1.append(S[0])
j=0
v=1
c=1
r=0
T=S[0]
for i in range(1,len(S)) :
    if v==0 and c==1 :
        v=1
        T=S[i]
    else :
        
        if S[i] in l1 :
            T=T+S[i]
        else :
            j=j+1
            if j<n :
                l.append(T)
                T=S[i]
                l1.append(S[i])
                l1.append(T[0])
            else :
                l.append(T+S[i:])
                r=1
                break
            v=0
            c=0
if r==0 :
    l.append(T)
if n==len(l) and n<26 :
    print('YES')
    for i in range(len(l)) :
        print(l[i])
else :
    print('NO')
            

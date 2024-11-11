s=input()
t=[ord(c)-65 for c in s]
solved=False
for i in range(len(t)-25):
    tp=t[i:i+26]
    l=[]
    for k in range(26):
        if tp.count(k)==0:
            l+=[k]
        if tp.count(k)>1:
            break
    else:
        if not solved:
            solved=True
            for j in range(i):
                print(s[j] if s[j]!='?' else 'A',end='')
            c=0
            for j in range(i,i+26):
                if s[j]!='?':
                    print(s[j],end='')
                else:
                    print(chr(l[c]+65),end='')
                    c+=1
            for j in range(i+27,len(t)):
                print(s[j] if s[j]!='?' else 'A',end='')        
if not solved:
    print(-1)
            
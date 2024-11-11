n=int(input())
k=input()
s=list(k)
c=0
for i in range(0,n-1,2):
    if(s[i]=='a'):
        if(s[i+1]=='b'):
            continue
        else:
            s[i+1]='b'
            c+=1
    else:
        if(s[i+1]=='a'):
            continue
        else:
            s[i+1]='a'
            c+=1
l=""
l=l.join(s)
print(c)
print(l)
            

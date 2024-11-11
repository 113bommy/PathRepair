s=input()
ns=''
for i in range(len(s)-1):
    if(s[i]=='v' and s[i+1]=='v'):
        ns+='w'
    else:
        ns+=s[i]
print(ns)
w=0
wo=0
wow=0
for i in ns:
    if(i=='w'):
        w+=1
        wow+=wo
    if(i=='o'):
        wo+=w
print(wow)
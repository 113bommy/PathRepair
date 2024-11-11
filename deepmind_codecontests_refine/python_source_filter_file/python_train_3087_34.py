n=int(input())
s=input()
l=[]
c=0
d={'a','e','i','o','u'}
for i in range(n):
    if(s[i] in d):
        c+=1
    else:
        c=0
    if(c<2):
        l.append(s[i])
print(''.join(l))

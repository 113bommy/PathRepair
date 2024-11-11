n=input()
s=list(input())
sp=[]
s1=['q','w','e','r','t','y','u','i','o','p']
s2=['a','s','d','f','g','h','j','k','l',';']
s3=['z','x','c','v','b','n','m',',','.','/']
if n=='L':
    for i in range(len(s)-1):
        if s[i] in s1:
            sp.append(s1[s1.index(s[i])+1])
        elif s[i] in s2:
            sp.append(s2[s2.index(s[i])+1])
        elif s[i] in s3:
            sp.append(s3[s3.index(s[i])+1])
if n=='R':
    for i in range(len(s)):
        if s[i] in s1:
            sp.append(s1[s1.index(s[i])-1])
        elif s[i] in s2:
            sp.append(s2[s2.index(s[i])-1])
        elif s[i] in s3:
            sp.append(s3[s3.index(s[i])-1])
for i in sp:
    print(i,end='')
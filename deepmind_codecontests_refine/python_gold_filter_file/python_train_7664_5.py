from sys import stdin
n=int(stdin.readline().strip())
d=dict()
for i in range(n):
    s=stdin.readline().strip().split()
    if s[0] in d:
        d[s[0]]+=s[2::]
    else:
        d.update({s[0]:s[2::]})
for i in d:
    d[i]=list(set(d[i]))
    rem=[]
    for j in range(len(d[i])):
        for k in range(len(d[i])):
            if k!=j and len(d[i][k])>=len(d[i][j]) and d[i][k][len(d[i][k])-len(d[i][j])::]==d[i][j]:
                rem.append(d[i][j])
    rem=set(rem)
    for j in rem:
        d[i].remove(j)

print(len(d))
for i in d:
    print(i,len(d[i]),*d[i])
        
                
                
        

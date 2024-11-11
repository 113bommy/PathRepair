n,m=map(int,input().split())
s1=input()
s2=input()
h=n
a=[]

for q in range(m-n+1):
    j=0
    b=[]
    r=q
    for w in range(n):
        if s1[w]!=s2[r]:
            b.append(r+1)
            j+=1
        r+=1    
        
    #print(b)
    if h>j:
        h=j
        a=b[:]
print(h)
print(*a)
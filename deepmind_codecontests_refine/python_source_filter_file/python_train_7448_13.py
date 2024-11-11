from math import inf
n,m  , c = input().split()
n,m = int(n) , int(m)
y  ,x , p= inf ,inf ,inf
ans = 0
l=[]
t = []
v=[]
for i in range(n):
    a= input()
    l.append(a)
    if c in a and p==inf:
        if i!=0:
            y = i-1        
        p =1
    if c in a:
        if i==n-1:
            x = inf
        if i!=n-1:
            x=i+1
        l1 = a.find(c)
        r= a.rfind(c)
        if l1!=0:
            
            if (not a[l1-1] in v) and a[l1-1]!="." :
                
                v.append(a[l1-1])
                ans+=1
        if r!=m-1:

            if (not a[r+1] in v) and a[r+1]!="." :
                
                v.append(a[r-1])
                ans+=1
        
v=[]
if n!=1:
    for i in range(m):
        if y!=inf:
            if l[y][i]!=".":
                if (not l[y][i] in v ) and l[y+1][i]==c :
                    v.append(l[y][i])
                    ans+=1
        if x!=inf:
            if l[x][i]!=".":
                if (not l[x][i] in v) and l[x-1][i]==c:
                    v.append(l[x][i])
                    ans+=1
print(ans)

        


            
            
            

    

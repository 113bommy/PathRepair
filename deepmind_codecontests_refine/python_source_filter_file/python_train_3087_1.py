n=int(input())
s=input()
l=list(s)
a=['a','e','i','o','u']
for i in range(n-1):
    if(l[i] in a):
        for j in range(i+1,n):
            if(l[j] in a):
                l[j]=1
            else:
                break
b=[]
for k in range(n):
    if(l[k]!=1):
        b.append(l[k])
        
s=''
print(s.join(b))

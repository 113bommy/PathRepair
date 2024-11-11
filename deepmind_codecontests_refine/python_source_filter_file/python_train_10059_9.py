
s=input()
n=len(s)
pa=[]
pb=[]
a=0
b=0
for i in range(n): 
    if s[i]=='a':
        a+=1 
    else:
        b+=1 
    pa.append(a)
    pb.append(b)
ans=[]
for i in range(n):
    for j in range(i,n):
        ans.append(pa[i] + pb[j]-pb[i]+pa[n-1]-pa[j])
print(max(max(ans),s.count('a'),s.count('b')))

    
    
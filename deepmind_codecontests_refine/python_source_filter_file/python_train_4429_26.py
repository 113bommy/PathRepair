# cook your dish here
n,c=map(int,input().split())
p=list(map(int,input().split()))
t=list(map(int,input().split()))
z=s=0
k=s1=0
a=[]
b=[]
for i in range(0,n):
    z=z+t[i]
    
    if c*z<p[i]:
        
        s=p[i]-c*z
        a.append(s)
        
print(a)
for j in range(len(p)-1,-1,-1):
    k=k+t[j]
    if c*k<p[j]:
        s1=p[j]-c*k
        b.append(s1)

print(b)

if sum(a)>sum(b):
    print("Limak")
elif sum(b)>sum(a):
    print("Radewoosh")
else:
    print("Tie")
        
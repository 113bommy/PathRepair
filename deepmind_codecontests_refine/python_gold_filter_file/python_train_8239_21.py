n=int(input())
l=list(map(int,input().split()))
e=l[0]
s=l[0]
a=[1]
for i in range(1,n):
    if 2*l[i]<=l[0]:
        e+=l[i]
        a.append(i+1)
    s+=l[i]
#print(e,s)
if 2*e>s:
    print(len(a))
    print(*a,sep=" ")
else:
    print(0)
    
    
    
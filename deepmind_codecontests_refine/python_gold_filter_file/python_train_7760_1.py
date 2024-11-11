n=int(input())
s=input()
l=[0]*n
for t in set(s): 
    j=-1
    for i in range(n):
        if s[i]==t:j=i
        if j==-1:l[i]=n
        else:l[i]=max(l[i],i-j+1)
print(min(l))
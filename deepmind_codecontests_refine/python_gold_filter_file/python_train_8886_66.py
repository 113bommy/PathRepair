n=int(input())
a=input()
c=0
for i in range(n-1):
    if(a[i]==a[i+1]):
        a.replace('',a[i])
        c+=1
print(c)
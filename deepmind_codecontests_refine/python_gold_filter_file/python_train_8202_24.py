n=int(input())
c=0
for i in range(1,int(n**0.5)+1):
    if n%i==0:
        if i<n//i-1 :
            c+=max(0,n//i-1)
print(c)
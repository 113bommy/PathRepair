n,k=map(int,input().split())
p=0
for i in range(1,n+1):
    c=0
    while i<k:
        i*=2
        c+=1
    p+=1/n*0.5**c
print(p)
n=int(input())
c=0
for i in range(n):
    p=int(input())
    if pow(2,p-1,p)==1:
        c+=1
print(c)

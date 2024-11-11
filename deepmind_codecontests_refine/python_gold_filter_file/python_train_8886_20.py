n=int(input())
m=list(input())
c=0
for i in range(1,n):
    if m[i-1]==m[i]:
        c+=1
print(c)

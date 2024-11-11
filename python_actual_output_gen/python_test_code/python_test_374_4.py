n=int(input())
a=input()
#c=["zero","one"]
z=0
for i in range(n):
    if a[i]=="Z":
        z+=1
p=int((n-4*z)/3)
ans=[0 for j in range(z+p)]
for j in range(p):
    ans[j]=1
print(*ans)




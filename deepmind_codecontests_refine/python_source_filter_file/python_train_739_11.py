n=int(input())
a=[]
for i in range(n):
    x=int(input())
    a.append(x)
for i in range(1,(2**n)):
    ans=0
    for j in range(4):
        if i & (1 << j):
            ans+=a[j]
    ans=ans*2-(sum(a))
    if ans%360==0:
        print("YES")
        exit()
print("NO")
n=int(input())
p=list(map(int,input().split()))

c=0
for i in range(n-1):
    if p[i-1]<=p[i]<=p[i+1] or p[i+1]<=p[i]<=p[i-1]:
        c+=1
print(c)

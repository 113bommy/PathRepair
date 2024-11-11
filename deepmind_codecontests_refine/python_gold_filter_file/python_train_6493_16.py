n=int(input())
s=n
for i in range(1,n+1):
    s+=i*(n-i)
print(s)
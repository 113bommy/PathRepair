n=int(input())
s=0
for i in range(1, n):
    s+=i*(n-i)
print(s+n)
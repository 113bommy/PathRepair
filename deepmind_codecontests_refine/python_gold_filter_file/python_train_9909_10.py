
n=int(input())
d=int(input())
e=int(input())
mn=n
e*=5
for i in range(n//e+1):
    mn=min(mn,(n-i*e)%d)
print(mn)
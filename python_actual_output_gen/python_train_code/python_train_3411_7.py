
n=int(input())
d=int(input())
e=int(input())
mn=n
e*=5
for i in range(n//d):
    mn=min(mn,(n-i*e)%d)
print(mn)
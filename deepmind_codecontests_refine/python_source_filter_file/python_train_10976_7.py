n,k=input().split()
n=int(n)
k=int(k)
x=input().split()
x=[int(i) for i in x]
x=[int(5-i) for i in x]
a=sum(i > k  for i in x)
print(int(a/3))
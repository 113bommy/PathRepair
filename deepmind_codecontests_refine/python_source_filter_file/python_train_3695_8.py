x=int(input())
k=int(input())

s=[int(n) for n in str(k)]
a=s.count(0)
b=s.count(1)
print(abs(a-b))
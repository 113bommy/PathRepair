n,k=[int(x) for x in input().split()]
x=[int(x) for x in  input().split()]
x.sort(reverse=True)
x=x[:4]
print(min(x))
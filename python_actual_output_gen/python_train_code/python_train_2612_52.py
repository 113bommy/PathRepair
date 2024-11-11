
n=int(input())
l=[int(i) for i in input().split()]
a=min(l)
b=max(l)
k=b-a
print(n-k+1)
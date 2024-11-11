a=list(map(int,input().split()))
n=int(input())
x=max(a)*(2**n)
print(x+sum(a)-max(a))

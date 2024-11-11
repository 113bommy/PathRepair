x=int(input())
a=list(map(int,input().split()))

b=list(set(a))
y=len(b)

print(2*y-x-y%2)

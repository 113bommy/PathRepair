x=int(input())
a=list(map(int,input().split()))

b=list(set(a))
y=len(b)

print(x-y-y%2)

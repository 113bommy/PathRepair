a=int(input())
x=1
y=1

l1=list(map(int,input().split(" ")))
l2=list(map(int,input().split(" ")))

for e1 in l1:
    x|=e1

for e2 in l2:
    y|=e2

print(x+y)

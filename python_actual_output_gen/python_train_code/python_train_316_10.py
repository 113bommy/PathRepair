input()
v=sorted(map(int,input().split()))
a=v.pop()
while v:
    a=(a+v.pop())/2
print(a)
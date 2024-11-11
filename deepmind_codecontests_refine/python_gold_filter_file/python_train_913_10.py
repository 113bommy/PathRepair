input()
v=sorted(map(int,input().split()))
a=v.pop(0)
while v:
    a=(a+v.pop(0))/2
print(a)
a,b = input().split()
l = list(map(int, input().split()))
x= len(l)
v= l[x-1]
w= sum(l)-v
if w<=int(b):
    print("YES")

else:
    print("NO")
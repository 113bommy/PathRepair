x,n=[int(i) for i in input().split()]
p=[int(i) for i in input().split()]
np=[i for i in range(0,101) if not i in p]
r=0
for i in np:
    if abs(x-i)<abs(x-r):
        r=i
print(r)

ct=0
a = int(input())
b = int(input())
c=a
while a < b:
    a = a * c
    ct += 1

if a == b:
    print("YES")
    print(ct)
else:
    print("NO")

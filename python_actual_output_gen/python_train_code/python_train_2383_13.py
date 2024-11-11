ct=0
a = int(input())
b = int(input())
while a < b:
    a = a * a
    ct += 1

if a == b:
    print("YES")
    print(ct)
else:
    print("NO")

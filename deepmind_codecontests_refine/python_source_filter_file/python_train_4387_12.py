n = input()
a = [i for i in input().split()]
for i in a:
    if n[0] == a[0] or n[1] == a[1]:
        print("YES")
        exit(0)
print("NO")
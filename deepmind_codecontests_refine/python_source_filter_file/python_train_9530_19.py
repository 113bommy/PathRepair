n = int(input())
for i in range(n):
    a = input().split(" ")
    if int(a[1]) >= 2400 and int(a[1]) > int(a[2]):
        print("YES")
        exit(0)
print("NO")

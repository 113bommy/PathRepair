n = int(input())
for i in range(n):
    a = input().split(" ")
    if int(a[1]) >= 2400 and int(a[2]) > int(a[1]):
        print("YES")
        exit(0)
print("NO")

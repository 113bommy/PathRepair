n = int(input())
a = [int(i) for i in input().split()]
a.sort(reverse=True)
for i in range(2, n):
    if a[i - 2] < a[i - 1] + a[i]:
        print("YES")
        exit(0)
print("NO")
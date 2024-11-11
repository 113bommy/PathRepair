n = int(input())
for i in range(1, n):
    if (i * (i+1))//2 == n:
        print("YES")
        exit(0)
print("NO")
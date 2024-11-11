n, k = map(int, input().split())

if (n == k):
    print("YES")
elif (n//k) % 2 == 0:
    print("NO")
elif (n//3)%2 == 1:
    print("YES")

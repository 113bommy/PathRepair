n = int(input())
a = list(map(int, input().split()))
x_n = a.count(max(set(a), key=a.count))
if (n//2) + n % 2 <= x_n:
    print("YES")
else:
    print("NO")
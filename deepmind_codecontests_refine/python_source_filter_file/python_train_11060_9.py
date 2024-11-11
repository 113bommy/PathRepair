t = int(input())
for i in range(t):
    n = int(input())
    if n % 4:
        print("No")
    else:
        print("YES")
        even = [i for i in range(2, n + 1, 2)]
        odd = [i for i in range(1, n//2 + 2, 2)]
        arr = even + odd + [sum(even) - sum(odd)]
        print(*arr)
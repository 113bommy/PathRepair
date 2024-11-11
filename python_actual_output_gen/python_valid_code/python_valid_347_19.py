n = int(input())
x = list(map(int, input().split()))
y = list(map(int, input().split()))
print("Yes" if sum(x) == sum(y) else "No")

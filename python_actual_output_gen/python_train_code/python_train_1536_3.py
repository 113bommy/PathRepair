n = int(input())
a = input().split()
print(max(0, sum(1 + (i + 1 == n or a[i + 1] == '0') for i in range(n) if a[i] == '1')))

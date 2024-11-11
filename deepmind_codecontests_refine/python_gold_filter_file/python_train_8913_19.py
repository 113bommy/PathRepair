n = int(input())
s = sum(map(int, input().split()))
a = s - n
b = s - 2*a
c = min(a, b)
print(c + max((b-c)//3, 0))



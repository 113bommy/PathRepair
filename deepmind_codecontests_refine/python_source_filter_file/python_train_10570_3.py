n = int(input())
s = [int(i) for i in input().split()]
a = max(s)
b = min(s)
c = sum(s)
print(a-(c-a-b))

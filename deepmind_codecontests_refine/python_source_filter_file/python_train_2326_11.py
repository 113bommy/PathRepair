d = int(input())
n = int(input())
a = list(map(int, input().split()))
s = 0
for i in range(n):
    s+=d - a[i]
print(s)

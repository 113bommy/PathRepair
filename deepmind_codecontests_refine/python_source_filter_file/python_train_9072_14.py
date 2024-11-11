n = int(input())
if n%2 == 0:
    m = n//2 + 1
else:
    m = (n+1)//2
print(m)
for i in range(m):
    print(1, i + 1)
for i in range(m - 1 - (1 - n%2)):
    print(n, i + 2)
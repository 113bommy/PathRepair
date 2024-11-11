x = int(input())
s = 0
maxi = 0
for i in range(x):
    y, z = map(int, input().split())
    s = s - y + z
    if s > maxi:
        maxi = s
print(maxi)
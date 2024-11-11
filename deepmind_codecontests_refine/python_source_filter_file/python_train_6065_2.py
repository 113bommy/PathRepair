n = int(input())
s = [int(i)for i in input().split()]
d = 0
for i in range(n):
    if i not in s:
        d+=1
print(d)
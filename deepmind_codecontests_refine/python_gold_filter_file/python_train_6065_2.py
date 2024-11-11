n = int(input())
s = [int(i)for i in input().split()]
d = 0
for i in range(n):
    if i+1 not in s:
        d+=1
print(d)
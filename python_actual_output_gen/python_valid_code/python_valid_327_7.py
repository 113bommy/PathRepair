n, m = [int(i) for i in input().split()]

res = 0

for i in range(n):
    s = input().split()
    for j in range(0, m+1, 2):
        if s[j] == '1' or s[j+1] == '1':
            res += 1
print(res)

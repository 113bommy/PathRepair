import sys
input=sys.stdin.readline
n = int(input())
s = input()
res = n * (n-1) // 2
     
for x in range(2):
    cur = 1
    for i in range(1,n):
        if s[i] == s[i-1]:
            cur += 1
        else:
            res -= cur - x
            cur = 1
    s = s[::-1][1:]
print(res)
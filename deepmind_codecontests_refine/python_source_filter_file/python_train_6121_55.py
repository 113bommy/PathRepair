n = int(input())
a = list(map(int, input().split())
s = [0] * n
for i,j in enumerate(a):
    s[j-1] = i+1
print(*s)
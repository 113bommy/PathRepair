n = int(input())
d = list(map(int,input().split()))
a, b = map(int, input().split())
s = 0

for i in range(a,b-a):
    s = s + d[i]

print(s)

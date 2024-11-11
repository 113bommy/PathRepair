n = int(input())
a = map(int, input().split())
s1 = 0
for i in a:
    s1 += abs(i)
print(s1)
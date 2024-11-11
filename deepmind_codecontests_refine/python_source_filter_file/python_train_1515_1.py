#n = int(input()) 
#n, m = map(int, input().split())
#s = input()
c = list(map(int, input().split()))
s = sum(c)
a = [0] * 101
for i in range(5):
    a[c[i]] += 1
l = 0
for i in range(100, 0, -1):
    if a[i] > 1:
        l = i * min(a[i], 3)
print(s - l)
    
l = []

s, n = input().split()
s = int(s)
n = int(n)

for i in range(n):
    a,b = input().split()
    a = int(a)
    b = int(b)
    l.append((a,b))
    
l.sort()

c = 0

for i in range(n):
    if s >= l[i][0]:
        s = s + l[i][1]
        c = c + 1

if c == n :
    print("YES")

else:
    print("NO")

n,k = map(int, input().split())
a = list(map(int, input().split()))
s = ""
t = 0
m = 0
c = 0
p = 0
for i in range(n):
    m = min(a)
    t = a.index(m)
    
    a[t] = 101
    c+=m
    if c>=k:
        break
    p += 1
    s += str(t+1) + " "

print(p)
print(s)
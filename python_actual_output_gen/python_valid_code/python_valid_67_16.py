n = int(input())
a = []
s = input()
t = s.split()
for k in t:
    if k != " ":
        a.append(k)
    
a = sorted(a)

if a[n-1] == a[n]:
    print("NO")
else:
    print("YES")
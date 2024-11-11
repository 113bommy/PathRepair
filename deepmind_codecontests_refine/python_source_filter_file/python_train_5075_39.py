n,b = map(int,input().split())
a = list(map(int,input().split()))
diff = []
e,o = 0,0
for i in range(n):
    if a[i]%2==0:
        e+=1
    else:
        o+=1
    if e==o and i!=(n-1):
        diff.append(abs(a[i]-a[i+1]))
a.sort()
c,s = 0,0
for i in diff:
    s += i
    c += 1
    if s>b:
        c-=1
        break
print(c)
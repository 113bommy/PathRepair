n,k = map(int,input().split())
a = list(map(int,input().split()))
t = list(map(int,input().split()))
s,su = [],0
for i in range(n):
    if t[i]==1:
        su+=a[i]
        s.append(0)
    else:
        s.append(a[i])
print(s)
c = sum(s[0:k])
mx = c
for i in range(k,n):
    c += s[i]-s[i-k]
    mx = max(mx,c)
print(su+mx)
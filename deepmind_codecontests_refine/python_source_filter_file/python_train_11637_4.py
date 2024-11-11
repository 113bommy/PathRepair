n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
cnta = [0]*(n+1)
cntb = [0]*(n+1)
ta = 0
tb = 0
s = [0]*(n+1)
for i in range(n):
    cnta[a[i]] += 1
    cntb[b[i]] += 1
    s[a[i]] += 1
    s[b[i]] += 1
if max(s) > n:
    print("No")
    exit()
print("Yes")
m = 0
for i in range(1,n+1):
    cnta[i] += cnta[i-1]
    cntb[i] += cntb[i-1]
for i in range(1,n+1):
    m = max(m,cnta[i]-cntb[i-1])
# print(m)
# print(cnta)
# print(cntb)
print(b[m:]+b[0:m])
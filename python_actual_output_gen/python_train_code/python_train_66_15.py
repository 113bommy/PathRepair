n = int(input())
s = input()
m = dict()
for i in range(0, n-1):
    x = s[i]+s[i+1]
    if x in m:
        m[x]+=1 
    else:
        m[x] = 1
ans = 0
a = ''
for x in m:
    if m[x]>ans:
        ans = m[x]
        a = x
print(x)
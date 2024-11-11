n=int(input())
s=[int(i) for i in input().split()]
m=0
t=0
for i in range(n):
    m=m+s[i]
if m%2==0:
    for j in range(n):
        if s[i]%2==0:
            t=t+1
if m%2!=0:
    for c in range(n):
        if s[i]%2!=0:
            t=t+1
print(t)

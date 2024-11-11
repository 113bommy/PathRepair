s=str(input())
m=0
n=len(s)
a=s[0]
s+=s[:-1]
t=0
for i in range(n*2-2):
    if s[i+1]==a:
        if t>m: m=t
        t=0
    else:
        t+=1
    if t==n: m=t
    a=s[i+1]

print(m+1)if m<n else print(n)

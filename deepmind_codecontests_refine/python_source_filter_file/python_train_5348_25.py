s=input()
n=len(s)
t=0
q=-1
for i in range(n):
    if s[i]=='0':
        t=1
        q=i
        break
for i in range(n):
    if t==0 and i==n-1:
        break
    if i!=q:
        print(s[i])
        
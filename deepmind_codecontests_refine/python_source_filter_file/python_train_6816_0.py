con = 1000000009
def Hash(s):
    h=0
    p=1
    for c in s:
        h=(h+p*ord(c))%con
        p=(p*197)%con
    return h
n,m=map(int,input().split())
a = set()
for i in range(n):
    s=input()
    h=Hash(s)
    p=1
    for j in range(len(s)):
       for k in range(97,100):
           if ord(s[j])!=k:
               a.add((h+p*(k-ord(s[j])))%con)
       p=(p*197)%con
ans=[]
for i in range(m):
    s=input()
    b=Hash(s)
    if b in a:
        ans.append('YES')
    else:
        ans.append('NO')
print ('\n'.join(ans))

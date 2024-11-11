mod = 1000000007
ii = lambda : int(input())
si = lambda : input()
dgl = lambda : list(map(int, input()))
f = lambda : map(int, input().split())
il = lambda : list(map(int, input().split()))
ls = lambda : list(input())
st='abcdefghijklmnopqrstuvwxyz#'
c=0
s=ls()
for i in range(len(s)):
    if s[i]==st[c]:
        c+=1
    elif ord(st[c])-ord(s[i])>=1:
        s[i]=st[c]
        c+=1
if c==26:
    print(''.join(s))
else:
    print(-1)
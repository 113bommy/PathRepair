mod = 1000000007
ii = lambda : int(input())
si = lambda : input()
dgl = lambda : list(map(int, input()))
f = lambda : map(int, input().split())
il = lambda : list(map(int, input().split()))
ls = lambda : list(input())
s=ls()
n=len(s)
for i in range(1,n-1):
    if s[i]==s[i-1]:
        for j in 'abc':
            if j!=s[i+1] and j!=s[i-1]:
                s[i]=j

if n>1 and s[-1]==s[-2]:
    for i in 'abc':
        if s[-2]!=i:
            s[-2]=i
print(''.join(s))

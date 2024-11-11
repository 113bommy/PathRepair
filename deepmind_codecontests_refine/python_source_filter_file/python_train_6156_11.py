mod = 1000000007
MOD = 998244353
ii = lambda :  int(input())
si = lambda :  input()
dgl = lambda : list(map(int, input()))
f = lambda :   map(int, input().split())
il = lambda :  list(map(int, input().split()))
it = lambda :  tuple(map(int, input().split()))
ls = lambda :  list(input())
n=ii()
s=si()
c1=0
for i in s:
    if i==s[0]:
        c1+=1
    else:
        break
c2=0
for i in s[::-1]:
    if i==s[-1]:
        c2+=1
    else:
        break
if s[0]==s[-1]:
    print((c1*c2)%MOD)
else:
    print((c1+c2-1)%MOD)

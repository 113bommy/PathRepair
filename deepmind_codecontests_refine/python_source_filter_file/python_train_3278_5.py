MOD = 1000000007
MOD2 = 998244353
ii = lambda : int(input())
si = lambda : input()
dgl = lambda : list(map(int, input()))
f = lambda : map(int, input().split())
il = lambda : list(map(int, input().split()))
ls = lambda : list(input())
s=si()
n=len(s)
for i in range(n):
    for j in range(i+1,n):
        for k in range(j+1,n):
            l=[s[i]+s[j]+s[k],s[i]+s[j],s[j]+s[k],s[i]+s[k],s[i],s[j],s[k]]
            for x in l:
                if int(x)%8==0:
                    print('YES')
                    print(x)
                    exit()
if s[0] in '08':
    print('YES')
    print(s[0])
elif n>1 and s[1] in '08':
    print('YES')
    print(s[1])
elif n>1 and int(s)%8==0:
    print('YES')
    print(s)
else:
    print('NO')
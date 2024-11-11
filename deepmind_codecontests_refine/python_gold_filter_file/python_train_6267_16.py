ret = 0
p = [True] * (100500)

for i in range(2,100300):
    for j in range(i*i,100300,i):
        p[j] = False
a = [i for i in range(2,100001) if p[i]]

n = int(input())
b = list(map(int,input().split()))

def f(x):
    sm = 0
    ths = 0
    chk = []
    for i in range(n):
        if b[i]:
            sm += 1
            chk.append(i)
            if sm == x:
                for j in chk:
                    ths += abs(j - chk[x // 2])
                chk = []
                sm = 0
    return ths
ans = 10**18
s = sum(b)
for x in a:
    if s % x == 0:
        ans = min(ans,f(x))
print(ans if ans != 10**18 else -1)
    
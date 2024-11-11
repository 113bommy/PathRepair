from sys import stdout
printn = lambda x: stdout.write(str(x))
inn = lambda : int(input())
inl   = lambda: list(map(int, input().split()))
inm   = lambda:      map(int, input().split())
ins = lambda : input().strip()
DBG = True  and False
BIG = 999999999
R = 10**9 + 7

def ddprint(x):
  if DBG:
    print(x)

def foo(x):
    b = []
    for i in range(n):
        b.append([y for y in a[i]])
    #ddprint(b)
    cnt = 0
    rem = [False]*m
    while cnt<m:
        #ddprint("in loop x {} cnt {} b, rem".format(x,cnt))
        #ddprint(b)
        #ddprint(rem)
        top = [0]*m
        ok = True
        for i in range(n):
            top[b[i][-1]] += 1
        for j in range(m):
            if top[j]>x:
                ok = False
                rem[j] = True
                cnt += 1
                if cnt==m:
                    return False
        if ok:
            return True
        for i in range(n):
            while len(b[i])>0 and rem[b[i][-1]]:
                b[i].pop()
    return True

n,m = inm()
a = []
for i in range(n):
    aa = inl()
    aa = [x-1 for x in aa]
    aa.reverse()
    a.append(aa)

ddprint(a)
mx = n
mn = 0
while mx>mn+1:
    mid = (mx+mn)//2
    if foo(mid):
        mx = mid
    else:
        mn = mid
print(mx)

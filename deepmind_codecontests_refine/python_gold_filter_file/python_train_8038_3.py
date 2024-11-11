import sys,os,io
import bisect
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

for _ in range (int(input())):
    n,t,a,b = [int(i) for i in input().split()]
    d = [int(i) for i in input().split()]
    ti = [int(i) for i in input().split()]
    arr = []
    for i in range (n):
        arr.append([ti[i],d[i]])
    arr.sort()
    t1 = []
    d1 = []
    for i in arr:
        t1.append(i[0])
        d1.append(i[1])
    ans = 0
    easy = 0
    if d1[0]==0:
        now = a
        easy += 1
    else:
        now = b
    curr = 1
    teasy = d1.count(0)
    final = max(min((t1[0]-1)//a, teasy),0)
    while(now<=t and curr<n):
        if t1[curr]>now:
            ans = curr
            rem = teasy - easy
            diff = t1[curr]-now
            can = (diff-1)//a
            final = max(final, ans+min(can,rem))
        if d1[curr]==0:
            now+=a
            easy += 1
        else:
            now+=b
        curr+=1
    if now <= t:
        ans = curr
        final = curr
    print(final)
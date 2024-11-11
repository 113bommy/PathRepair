import bisect
n,m = map(int, input().split( ))
listt = list(map(int, input().split( )))
listt.sort()
pos = bisect.bisect_right(listt,m)
if(m == n):
    print(n)
else:
    print((n-pos)*2 + pos)
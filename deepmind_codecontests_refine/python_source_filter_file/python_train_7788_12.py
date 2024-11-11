from collections import Counter
N = int(input())
a = list(map(int,input().split()))
even = [[0,0]] + sorted([v,k] for k,v in Counter(a[1::2]).items())
odd = [[0,0]] + sorted([v,k] for k,v in Counter(a[0::2]).items())

if even[-1][1] != odd[-1][1]:
    print(N - even[-1][0] - odd[-1][0])
else:
    print(max(N - even[-1][0] - odd[-2][0], N - even[-2][0] - odd[-1][0]))

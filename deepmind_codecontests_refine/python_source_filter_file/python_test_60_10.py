from collections import defaultdict
t = int(input())
for x in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    k = sum(a) - (((n-2)*(sum(a)))//n)
    #print(k)
    d = defaultdict(lambda : 0)
    count = 0
    for i in a:
        if (k - i) in d:
            count += d[k-i]
        d[i] += 1
    print(count)

k = int(input())
n = [int(i) for i in list(input())]
s = sum(n)
if(s>=k):
    print(0)
else:
    l = k - s
    p = sorted(n)
    o = 0
    for i in range(len(p)):
        while(l>0):
            l-=(9-p[i])
            o+=1
    print(o)

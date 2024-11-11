s1,s2 = sorted([input() for i in range(2)], key = lambda x: len(x))
l1, l2 , r = len(s1), len(s2), 0
for i in range(1,l1+1):
    if l1%i == 0 and l2%i == 0:
        c1,c2 = int(l1/i),int(l2/i)
        if c1*s1[:i] == s1 and c2*s1[:i] == s2: r+=1
print(r)
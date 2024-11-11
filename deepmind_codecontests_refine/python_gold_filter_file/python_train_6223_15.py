s = input()
t = input()
n, m = len(s), len(t)
print(min(sum(si != ti for si, ti in zip(s[i: i+m], t)) for i in range(n-m+1)))

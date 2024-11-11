_, *s = map(int, open(0))
S = sum(s)
t = [i for i in s if i%10]
print(S if S%10 else S-min(t) if t else 0)
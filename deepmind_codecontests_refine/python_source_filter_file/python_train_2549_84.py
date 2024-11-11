import itertools
s=input()
n=len(s)
s=''.join(ch for ch, _ in itertools.groupby(s))
print((n+1)*26-n-(n-len(s)))
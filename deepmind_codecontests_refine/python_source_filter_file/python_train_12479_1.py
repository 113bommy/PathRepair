import itertools,sys
def f(a):
 if len(a)<2:yield[a[0]]*2
 for i in range(1,len(a)):
  for p,s in f(a[:i]):
   for q,t in f(a[i:]):
    yield(p+q,f'({s} + {t})')
    yield(p-q,f'({s} - {t})')
    yield(p*q,f'({s} * {t})')
def s(a):
 for p in itertools.permutations(a):
  for n,s in f(p):
   if n==10:print(s);return 1
for e in iter(input,'0 0 0 0\n'):
 a=list(map(int,e.split()))
 if not s(a):print(0)

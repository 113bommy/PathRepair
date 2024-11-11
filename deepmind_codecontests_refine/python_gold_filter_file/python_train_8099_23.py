import re, copy
import itertools
N= int(input())

pat='(AGC|ACG|GAC|AGAC|AGTC|AGCC|AAGC|ATGC|AGGC)'
repattern = re.compile(pat)

memo={}

for s in itertools.product('ATGC', repeat=3):
  if not repattern.search(''.join(s)):
  	memo[''.join(s)] = 1
  
for _ in range(3,N):
  new_memo={}
  for k,v in memo.items():
    for c in 'ATGC':
      if not repattern.search(k+c):
        new_memo[(k+c)[-3:]] = new_memo.get((k+c)[-3:],0)+v
  memo=new_memo

print(sum(memo.values())%(10**9+7))
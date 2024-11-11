from collections import Counter
n = int(input())
def score(s):
  return Counter(s).most_common()[0][1];
a = [input() for i in range(3)]
l = len(a[0])
a = list(map(score, a))
if n == 1:
  a = list(map(lambda x: x - 1 if x == l else x + 1, a))
else:
  a = list(map(lambda x: x + 1, a))
print('Draw' if a.count(max(a)) > 1 else [['Kuro', 'Shiro', 'Katie'][i] for i in range(3) if a[i] == max(a)][0])

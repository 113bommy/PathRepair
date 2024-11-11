s = input()
K = int(input())

l = set([])
for i in range(len(s)):
  for j in range(i, len(s)):
    l.add(s[i:j+1])
l2 = list(l)
l2.sort()
print(l2[K-1])
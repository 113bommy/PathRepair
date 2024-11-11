import bisect

N = int(input())
S = list(str(input()))

def ordN(x):
  return ord(x) - ord('a')

li = [[] for _ in range(26)]
for i,s in enumerate(S):
  li[ordN(s)].append(i)

for i in range(int(input())):
  Q1, Q2, Q3 = input().split()
  if Q1 == "1":
    Q2 = int(Q2) - 1
    if S[Q2] != Q3:
      I = bisect.bisect(li[ordN(S[Q2])], Q2)
      li[ordN(S[Q2])].pop(I)
      bisect.insort(li[ordN(Q3)], Q2)
      S[Q2] = Q3
  else:
    Q2, Q3 = int(Q2)-1, int(Q3)-1
    count = 0
    for j in range(26):
      I = bisect.bisect_left(li[j], Q2)
      if I < len(li[j]) and li[j][I] <= Q3:
        count += 1
    print(count)
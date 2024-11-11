from collections import Counter

N = int(input())
V = list(map(int,input().split()))
even = Counter(V[1::2]).most_common()+([0, 0])
odd = Counter(V[::2]).most_common()+([0, 0])
if(even[0][0] != odd[0][0]):
  print(N-even[0][1]-odd[0][1])
else:
  print(min(N-even[1][1]-odd[0][1], N-even[0][1]-odd[1][1]))

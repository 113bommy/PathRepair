n, m = [int(n) for n in input().split()];
S = input();
T = input();

minD = n
minMI = [] 
diff = 0
missedIndexes = []
for i in range(m - n + 1):
  for j, s in enumerate(S):
    if T[i+j] != s:
      diff+= 1
      missedIndexes.append(j)
  if(diff < minD):
    minD = diff
    minMI = missedIndexes
  diff = 0
  missedIndexes = []

print(minD)
print(" ".join([str(i+1) for i in minMI]))
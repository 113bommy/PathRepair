S = input()
X = []
for i in range(len(S)-2):
  X.append(abs(int(S[i:i+3])-753))
print(min(X))
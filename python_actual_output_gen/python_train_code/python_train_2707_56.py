S = input()
l = []
for i in range(len(S)-2):
  l.append(abs(int(S[i:i+2])-753))

print(min(l))
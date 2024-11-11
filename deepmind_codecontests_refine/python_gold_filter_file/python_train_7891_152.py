S = input()
p=[]
for i in range(len(S)-2):
  p.append(abs(int(S[i:i+3])-753))

print(min(p))
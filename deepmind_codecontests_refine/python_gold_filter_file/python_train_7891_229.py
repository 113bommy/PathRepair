S = input()
A = []

for n in range(len(S)-2):
  A.append(abs(int(S[n:n+3])-753))

print(min(A))
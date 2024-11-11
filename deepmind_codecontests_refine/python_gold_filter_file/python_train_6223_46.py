S = input()
T = input()

def d(s,t):
  return sum([1 if i!=j else 0 for i,j in zip(s,t)])

print(min([d(S[i:], T) for i in range(len(S)-len(T) + 1)]))

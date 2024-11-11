S=input()
print(min(abs(int(S[t:t+3])-753) for t in range(len(S)-2)))
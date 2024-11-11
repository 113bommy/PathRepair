S = input()
print(min(abs(int(S[j:j+3]) - 753) for j in range(len(S)-2)))
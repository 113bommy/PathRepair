S = input()
print(min([753 - int(S[i:i+3]) for i in range(len(S)-3 + 2)]))

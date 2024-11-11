S=input()
print(min([abs(int(S[i:i+2])-753) for i in range(len(S)-2)]))
S = input().strip()
print(min(abs(753 - int(S[i:i+3])) for i in range(0,len(S)-2,3)))
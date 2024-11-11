S = input()
kk = 0
for i in range(len(S)):
    if i+kk < len(S)-1 and S[i+kk] == '.':
        print(0, end='')
    elif i+kk < len(S)-1 and S[i+kk] == '-' and S[i+kk+1] == '.':
        print(1, end = '')
        kk += 1
    elif i+kk < len(S)-1 and S[i+kk] == '-' and S[i+kk+1] == '-':
        print(2, end='')
        kk += 1
    else:
        break

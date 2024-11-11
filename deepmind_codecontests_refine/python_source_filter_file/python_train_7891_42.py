S = input()
print(min((abs(765 - int(S[i:i+2])) for i in range(S-2))))

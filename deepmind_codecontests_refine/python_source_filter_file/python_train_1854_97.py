s=input()
print("Good" if any([s[i]!=s[i+1] for i in range(len(s)-1)]) else "Bad")
Alphabet = "abcdefghijklmnopqrstuvwqyz"
X = input()
Checked = []
i, Index = 0, 0
while i < len(X):
    if X[i] not in Checked and X[i] == Alphabet[Index]:
        Checked.append(Alphabet[Index])
        Index += 1
    elif X[i] not in Checked and X[i] != Alphabet[Index]:
        print("NO")
        exit()
    i += 1
print("YES")

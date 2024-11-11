s = input()
S = "CODEFESTIVAL2016"
count = 0
for i in range(15):
    if s[i] != S[i]:
        count+=1
print(count)
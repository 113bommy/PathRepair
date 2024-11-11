s = input()
s2 = input()
step = 0
for i in range(len(s2)):
    if s[i] == s2[i]:
        step+=1

print(step+1)

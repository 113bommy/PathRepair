s=input()
t=input()
for i in range(len(s)-1):
    if s==t[i:]+t[:i]:print("Yes");exit()
print("No")
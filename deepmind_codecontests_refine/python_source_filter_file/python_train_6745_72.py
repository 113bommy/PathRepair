s=input()
t=s[::-1]
cnt=0
for i in range(len(t)):
    if s[i]!=t[i]: cnt+=1
print(cnt)
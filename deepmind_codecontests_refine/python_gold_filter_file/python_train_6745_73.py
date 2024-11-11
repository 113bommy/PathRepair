s=input()
t=s[::-1]
cnt=0
for i in range(len(t)//2):
    if s[i]!=t[i]: cnt+=1
print(cnt)
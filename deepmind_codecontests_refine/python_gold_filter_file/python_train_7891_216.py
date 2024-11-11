s=input()
ans=999
for i in range(len(s)-2):
    ans=min(ans,abs(int(s[i:i+3])-753))
print(ans)
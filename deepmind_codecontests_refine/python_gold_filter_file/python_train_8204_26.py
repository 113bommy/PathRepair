n,s=int(input()),input()
mx=-1
for i in range(n):
    mx=max(mx,len(set(s[:i])&set(s[i:])))
print(mx)
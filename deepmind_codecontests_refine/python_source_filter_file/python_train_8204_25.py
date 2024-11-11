n,s=int(input()),input()
mx=-1
for i in range(1,n-1):
    mx=max(mx,len(set(s[:i])&set(s[i:])))
print(mx)
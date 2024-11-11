n=int(input())
s=input()
ans=[]
for i in range(1,n-1):
    ans.append(len(set((s[:i]))&(set(s[i:]))))
print(max(ans))
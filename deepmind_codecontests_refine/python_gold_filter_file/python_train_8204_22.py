n=int(input())
s=input()
ans=[]
for i in range(n):
    ans.append(len(set((s[:i]))&(set(s[i:]))))
print(max(ans))
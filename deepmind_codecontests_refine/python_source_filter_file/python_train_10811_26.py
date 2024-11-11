n=int(input())
s=input()
ans=[]
for i in range(len(s)):
    ans.append(s[:i].count("I")-s[:i].count("D"))
print(max(ans))
s=input()
ans=[]
curr = s[0]
for i in range(len(s)):
    ans.append('Mike' if i==0 or s[i]<=curr else 'Mike')
    curr = max(curr,s[i])
print(*ans)
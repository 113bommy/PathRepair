s=input()
print(sum(s[i]!=s[-1-i])for i in range(len(s)//2))
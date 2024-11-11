s=input()
n=len(s)
def dfs(i,x):
    if i==n-1:
        return sum(list(int,x.split('+')))
    return dfs(i+1,x+s[i+1])+dfs(i+1,x+'+'+s[i+1])
print(dfs(0,s[0]))
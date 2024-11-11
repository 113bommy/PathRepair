n=int(input())
abc='abcdefghih'
def dfs(i,a,s):
    if i==n:
        print(s)
    else:
        for j in range(0,a+1):
            dfs(i+1,j+1,s+abc[j])
dfs(0,0,'')
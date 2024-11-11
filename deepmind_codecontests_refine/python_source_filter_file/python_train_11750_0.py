def dfs(i, f):
    if i == n:
        return sum(list(map(int, f.split("+"))))
    return dfs(i+1, f+s[i+1])+\
           dfs(i+1, f+"+"+s[i+1])

s = input()
n = len(s)
print(dfs(0, s[0]))
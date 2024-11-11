n = int(input())
a = ["a","b","c","d","e","f","g","h","i","j"]
def dfs(s, max_x, LEN):
  if LEN == n:
    print(s)
  else:
    for c in a[:a.index(max_x)+2]:
      dfs(s+c, max(max_x,c), LEN+1)
dfs("a", "a", 1)
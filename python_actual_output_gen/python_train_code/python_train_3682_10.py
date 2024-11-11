sl, tl = [int(x) for x in input().split()]
s = input()
t = input()
sa = s.split("*")
ans = "No"
if len(sa) == 1 and s == t:ans =  "yes"
if len(sa) == 2 and len(sa[0]) + len(sa[1]) >= sl and t.startswith(sa[0]) and t.endswith(sa[1]):ans = "yes"
print(ans)
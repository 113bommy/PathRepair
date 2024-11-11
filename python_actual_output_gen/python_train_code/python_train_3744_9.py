input()
s = input()
u,d,l,r = s.count('U'), s.count('D'), s.count('L'), s.count('R')
print(min(u, d)+min(l, r))
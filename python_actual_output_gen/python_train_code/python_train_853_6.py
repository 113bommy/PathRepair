n = int(input())
t = [*map(int, input())]
f = sorted(t[:n])
l = sorted(t[n:])

try: a = [*map(lambda a,b:(a-b)/abs(a-b), f, l)]
except: print(-1);exit()

print('YNEOS'[len(set(a))!=1::2])


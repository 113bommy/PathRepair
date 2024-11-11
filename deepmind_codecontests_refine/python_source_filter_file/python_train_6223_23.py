s=input()
t=input()
print(len(t)-min(sum(x!=y for x,y in zip(s[i:],t))for i in range(-~len(s)-len(t))))
s=input()
t=input()
print(min(sum(x!=y for x,y in zip(s[i:],t))for i in range(-~len(s)-len(t))))
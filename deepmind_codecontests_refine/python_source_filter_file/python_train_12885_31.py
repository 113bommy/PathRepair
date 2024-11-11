s  = input()
t = input()
result = len([a,b for a,b in zip(s,t) if a != b])
print(result)
s = input()
t = input()
result = len([_ for a,b in zip(s,t) if a != b])
print(result)
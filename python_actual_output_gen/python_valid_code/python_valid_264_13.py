s = input()
t = input()
result = len([e for a,b in zip(s,t) if a != b])
print(result)
s = input()
r = []
for i in range(1,6):
  for j in range(len(s)-i):
    r.append(s[j:j+i])
print(sorted((set(r)))[int(input())-1])
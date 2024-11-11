s = int(input())
while len(set(str(s+1))) < 4: s += 1;
print(s+1)

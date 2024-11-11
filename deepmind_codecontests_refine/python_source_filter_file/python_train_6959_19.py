n = int(input())
lis = []

for a in range(1, int(n**0.5)):
  if n % a == 0:
    lis.append(max(a, int(n/a)))

print(len(str(min(lis))))
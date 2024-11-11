n = int(input())
s = set()
for i in range(n):
  s = s ^ {input()} 
print(len(s))
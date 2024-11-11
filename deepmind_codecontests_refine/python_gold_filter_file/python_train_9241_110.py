N = int(input())
s = input()

if len(s) > N:
  s = s[:N] + "..."
  
print(s)
s = input()
k = int(input())

substrings = set()
n = len(s)
for i in range(n):
  for j in range(i+1,k+1):    
    substrings.add(s[i:j])
    
print(sorted(substrings)[k-1])
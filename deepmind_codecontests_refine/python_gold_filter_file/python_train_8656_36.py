cases = int(input())
for case in range(cases):
  largo = int(input())
  s = input()
  if "8" in s and s.index("8") <= largo - 11:
    print("YES")
  else:
    print("NO")
    
  
    
  

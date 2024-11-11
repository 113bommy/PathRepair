word = input()
output = ''
v = ['a', 'e', 'i', 'o', 'u']
s = 0
while True:
  if s+1 < len(word) and s+2 < len(word):
    if v.count(word[s]) == 0 and v.count(word[s+1]) == 0 and v.count(word[s+2]) == 0:
      if len(set(word[s]+word[s+1]+word[s+2])) > 1:
        output+=(word[s]+word[s+1]+" ")
        s += 2
      else:
        output+=(word[s]*3)
        s += 1
    else:
      output+=word[s]
      s += 1
  else:
    output+=word[s]
    s += 1
  if s >= len(word):
    break
    
print(output)  

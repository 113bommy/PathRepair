from string import ascii_lowercase

n = int(input())
s = input()

wordsLen = 0
wordsInside = 0
flagInside = False
currWord = ""

for i in range(n):
  if(s[i]=='_'):
    currWord = ""
    continue
  elif(s[i]=='('):
    currWord = ""
    flagInside = True
  elif(s[i]==')'):
    currWord = ""
    flagInside = False
  elif s[i].lower() in ascii_lowercase:
    currWord+=s[i]
    if i+1<n:
      if s[i+1]=='_' or s[i+1]==')' or s[i+1]=='(':
        if flagInside:
          wordsInside+=1
        else:
          wordsLen = max(wordsLen, len(currWord))
  
if s[n-1].lower() in ascii_lowercase:
  wordsLen = max(wordsLen, len(currWord))
  
print(wordsLen, wordsInside)
  


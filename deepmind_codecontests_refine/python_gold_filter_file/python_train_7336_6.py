def getResultR(s, t, i, resultSoFar, nextCharPref, hasSuchString):
  #print(s[i], t[i], i, nextCharPref, resultSoFar)
  if (i == len(s)):
    return hasSuchString, resultSoFar
  if (hasSuchString):
    return getResultR(s, t, i+1, resultSoFar + 'a', nextCharPref, hasSuchString)
  gap = ord(t[i]) - ord(s[i])
  #print(gap)
  if nextCharPref == 0:
    if gap == 0:
      return getResultR(s, t, i+1, resultSoFar + s[i], nextCharPref, hasSuchString)
    if gap > 1:
      return getResultR(s, t, i+1, resultSoFar + chr(ord(s[i]) + 1), nextCharPref, True)
    elif gap == 1:
      hasLower, resultLower = getResultR(s, t, i+1, resultSoFar + chr(ord(s[i])), 1, hasSuchString)
      hasUpper, resultUpper = getResultR(s, t, i+1, resultSoFar + chr(ord(t[i])), -1, hasSuchString)
      if hasLower:
        return (hasLower, resultLower)
      else:
        return (hasUpper, resultUpper)
  elif nextCharPref == 1: # we select the lower character, thus now prefer to go up by 1
    nextChar = chr(ord(s[i]) + 1)
    if isValidChar(nextChar):
      return getResultR(s, t, i+1, resultSoFar + nextChar, nextCharPref, True)
    else:
      return getResultR(s, t, i+1, resultSoFar + s[i], nextCharPref, False)
  elif nextCharPref == -1: # we select the higher character, thus now prefer to go up by 1
    nextChar = chr(ord(t[i]) - 1)
    if isValidChar(nextChar):
      return getResultR(s, t, i+1, resultSoFar + nextChar, nextCharPref, True)
    else:
      return getResultR(s, t, i+1, resultSoFar + t[i], nextCharPref, False)       

def isValidChar(nextChar):
  return ord(nextChar) >= 97 and ord(nextChar) <=122 

def getResult(s, t):
  hasResult, result = getResultR(s, t, 0, "", 0, False)
  if hasResult:
    print(result)
  else:
    print("No such string")

#getResult("vklldrxnfgyorgfpfezvhbouyzzzzz",
#          "vklldrxnfgyorgfpfezvhbouzaaadv")
getResult(input(), input())
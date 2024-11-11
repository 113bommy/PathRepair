import sys

def check():
  games_played = int(sys.stdin.readline())
  results = []
  for i in range(games_played):
    results.append(int(sys.stdin.readline()[0]))
  log = ["AB"]
  for i in range(1, games_played):
    if results[i-1] is 1:
      if log[i-1] is "AB":
        log.append("AC")
      elif log[i-1] is "AC":
        log.append("AB")
      else:
        return False
    elif results[i-1] is 2:
      if log[i-1] is "AB":
        log.append("BC")
      elif log[i-1] is "BC":
        log.append("AB")
      else:
        return False
    elif results[i-1] is 3:
      if log[i-1] is "AC":
        log.append("BC")
      elif log[i-1] is "BC":
        log.append("AC")
      else:
        return False
  return True
  
if check():
  print("YES")
else:
  print("NO")
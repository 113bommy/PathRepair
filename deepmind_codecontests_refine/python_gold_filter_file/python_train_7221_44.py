for i in range(1, 6):
  try: 
    index = input().index('1')//2 + 1
    break
  except: pass
print(abs(i-3)+abs(index-3))
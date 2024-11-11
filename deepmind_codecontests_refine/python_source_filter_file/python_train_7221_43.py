for i in range(1, 6):
  try: 
    index = input().index('1')//2 + 1
    break
  except: pass
print((i-3)+(index-3))
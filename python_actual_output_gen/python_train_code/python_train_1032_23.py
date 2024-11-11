s=input()
if 'week' in s:
      x=int(s[:1])
      if(x==1)or(x==2):
            print(53)
      else:
            print(52)
else:
      x=int(s[:2])
      if(x<=29):
            print(12)
      elif(x==30):
            print(11)
      else:
            print(7)

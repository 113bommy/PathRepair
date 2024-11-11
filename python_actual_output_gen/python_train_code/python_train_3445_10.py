time = input().split(':')
h = int(time[0])

if int(time[1]) >= int(time[0][::-1]):
  
  hour = str((h+1)%24)
  
  while hour[::-1] >= '60' :
    h += 1
    hour = str((h)%24)
    
  if 1 == len(hour) :
        hour = '0'+ hour
  
  print(hour+':'+hour[::-1])

else :
  hour = str((h)%24)

  while hour[::-1] >= '60' :
    
    h += 1
    hour = str((h)%24)
    
  if 1 == len(hour) :
    hour = '0'+ hour

  print(hour+':'+hour[::-1])

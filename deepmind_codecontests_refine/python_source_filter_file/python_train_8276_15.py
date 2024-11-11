
def add(time, hour, minute):
  

  x = (hour % 24) if hour>24 else hour

  if time['hour'] + x > 23:
    time['hour'] = abs(24 - (x+time['hour']))
  else:
    time['hour'] += hour

  if time['minute'] + minute > 59:
    time['minute'] = abs(60 - (time['minute'] + minute))

    if time['hour'] + 1 > 23:
      time['hour'] = 0
    else:
      time['hour'] += 1
  else:
    time['minute'] += minute
  
  return time


def formatHour(time):
  out = ""

  if time['hour'] >= 10:
    out += str(time['hour']) + ":"
  else:
    out += "0"+str(time['hour']) + ":"
  

  if time['minute'] >= 10:
    out += str(time['minute'])
  else:
    out += "0"+str(time['minute'])
  
  return out

hour24 = input()
minute = int(input())

h, m = map(int, hour24.split(":"))


time = {
  "hour": h,
  "minute": m
}


if (minute/60) == int(minute/60):
  h = int(minute/60)
  m = 0
else:
  h = int(minute/60)
  m = minute - int(minute/60) * 60


add(time, h, m)

print(formatHour(time))

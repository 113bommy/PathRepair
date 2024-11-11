s=input().split(':')
hour , minute = int(s[0]) , int(s[1])
time  = int(input())
hr = time//60
mi = time%60

hour+=hr
minute+=mi

hour+=minute//60

minute%=60

if hour>=24:
  hour%=12

hour , minute = str(hour) , str(minute)

if len(hour) == 1:
  hour = '0'+hour
if len(minute) == 1:
  minute = '0'+minute

print(hour+':'+minute)
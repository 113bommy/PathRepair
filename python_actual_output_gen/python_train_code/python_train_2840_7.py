s = input()
n = int(input())
h = n // 1440
min = n%1440
a=0
if (int(s[3:])+min)//60 :a=(int(s[3:])+min)//60
min = str((int(s[3:])+min)%60)
if len(min)==1:min='0'+min
h = str((int(s[0:2])+h+a)%24)
if len(h)==1:h='0'+h
print(h+':'+min)
s = input().split(':')

n = int(input())
s = int(s[0]) * 60 + int(s[1]) + n

if (s >= 24*60): s%=(24*60)

hr = str(s // 60).rjust(2 , '0')
s %=60
mi = str(s).rjust(2 , '0')

print(f"{hr}:{mi}")
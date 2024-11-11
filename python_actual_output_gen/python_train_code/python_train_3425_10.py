s = input().split(":")
t = input().split(":")

start = int(s[0])*60 + int(s[1])
time = int(t[0])*60 + int(t[1])

ans = start - time

if ans < 0:
	ans = 24*60 + ans

hours = ans // 60
minutes = ans % 60

if hours < 10:
	print("0{}:".format(hours), end="")
else:
	print("{}:".format(hours), end="")

if minutes < 10:
	print("0{}".format(minutes))
else:
	print("{}:".format(minutes))
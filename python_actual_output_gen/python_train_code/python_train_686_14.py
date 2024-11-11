key=int(input())
s=input()
for x in s:
	print(chr((ord(x)-64 + key%26)%26 + 64),end='')
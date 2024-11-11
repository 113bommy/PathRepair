#!/usr/bin/python3.4
s = input()
if (len(s) == 1 and s.islower()):
	print (s.upper())
if(s.isupper()):
	print (s.lower())
elif (s[0].islower() and s[1:len(s)].isupper()):
	print (s[0].capitalize()+s[1::].lower()) 
else:
	print (s)
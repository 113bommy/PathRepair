s = input()
t = input()
p = ""
h = 0 
m = 0


if(int(s.split(':')[0]) < int(t.split(':')[0])):
	h = int(s.split(':')[0]) + 24 - int(t.split(':')[0])
else:
	h = int(s.split(':')[0]) - int(t.split(':')[0])

if(int(s.split(':')[1]) < int(t.split(':')[1])):
	m = int(s.split(':')[1]) + 60 - int(t.split(':')[1])
	if((int(s.split(':')[0]) == int(t.split(':')[0])) and m == 59):
	    h = int(s.split(':')[0]) + 1
	elif(int(s.split(':')[0]) == int(t.split(':')[0])):
	    h = int(s.split(':')[0])
	else:
	    h -= 1
else:
	m = int(s.split(':')[1]) - int(t.split(':')[1])

if(int(s.split(':')[0]) == 0 and int(t.split(':')[0]) == 0 and int(s.split(':')[1]) == 0 and int(t.split(':')[1]) == 1):
    h = 23

if(h < 10):
	p = "0" + str(h)
else:
	p = str(h)
if(m < 10):
	p += ":0" + str(m)
else:
	p += ":" + str(m)
 
print(p)
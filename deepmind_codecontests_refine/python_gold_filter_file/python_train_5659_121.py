x=input("")

x= x.replace('WUB', ' ')
if x[0:1]== " ":
	    x=x[1:]
if x[-1:-2]== " ":
	    x=x[:-2]
print(x)
a=input()
def decide(a):
	def loop(x,b):
		if a[0]=="H" or a[0]=="Q" or a[0]=="9":
			return "YES"
		elif len(b)>1:
			return loop(x+1,b[0])
		else:
			return "NO"
	return loop(0,a)
print (decide(a))
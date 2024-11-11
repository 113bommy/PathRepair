s=input()
def fun():
		t=["[","<","{","("]
		t1=["]",">","}",")"]
		res=[]
		summ=0
		for i in range(len(s)):
			try:
				if (s[i] in t):
					res.append(s[i])
				elif s[i] in t1:
					d=len(res)-1
					if t.index(res[d])!=t1.index(s[i]):
						summ+=1
					res.pop(d)
			except:
				print("Impossible",i)
				break
		else:
			if len(res)==0:
				print(summ)
			else:
				print("Impossible")
fun()
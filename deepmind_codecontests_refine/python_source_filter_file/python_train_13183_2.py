
def permute(a,b):
	d={}
	if len(a)==len(b) and len(a)==1:
		if int(a)==int(b):
			return a
		else:
			return "-1"
	for alpha in a:
			try:
				d[alpha]+=1
			except KeyError:
				d[alpha]=1

	if len(a)<len(b):
		strs=""
		for i in range(0,10)[::-1]:

			try:

				strs+=d[str(i)]*str(i)
			except:
				pass


		return strs
	elif len(a)==len(b):
		try:
			i=d[b[0]]
			s=permute(a.replace(b[0],"",1),b[1:])
			if s!="-1":

				return b[0]+s
			else:
				i=int(b[0])-1
				while i>=0:
					try:
						d[str(i)]-=1
						strs=str(i)
						for i in range(0,10)[::-1]:
							try:

								strs+=d[str(i)]*str(i)
							except:

								pass
						return strs
					except:
						i-=1
				return "-1"

		except KeyError:
			i=int(b[0])-1
			while i>=0:

				try:
					d[str(i)]-=1
					strs=str(i)
					for i in range(0,10)[::-1]:
						try:

							strs+=d[str(i)]*str(i)
						except:

							pass
					return strs
				except:
					i-=1
			return "-1"

a=(input())
b=(input())
d={}

print(permute(a,b))
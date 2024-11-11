def li ():
	return list (map (int, input ().split ()))


def num ():
	return map (int, input ().split ())


def nu ():
	return int (input ())
	
def solve ():
	t=1
	for _ in range(t):
		n,z=num()
		a=li()
		a.sort()
		cc=0
		l=0
		end=n//2+1
		while(l<=end):
			mid=(l+end)//2
			fl=True
			for i in range(mid):
				if((a[n-mid+i]-a[i])<z):
					fl=False
					break
			if(fl):
				l=mid+1
			else:
				end=mid-1
		print(end)




if __name__ == "__main__":
	solve ()
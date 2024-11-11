
while True:
	try:
		n=int(input())
		cnt=0
		for a in range(10):
			if a<=n:
				for b in range(10):
					if b<=n:
						for c in range(10):
							if c<=n:
								d = n-(a+b+c)
								if 0<=d<=9:
									cnt+=1
							else:
								break
					else:
						break
			else:
				break
		print(cnt)
	except EOFError:
		break
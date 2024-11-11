n=int(input())
l=list(map(int,list(str(n))))
if 7 in l or 9 in l or (n>=13 and n<=29) or 1 in l or n==10 or n==11 or (n>=70 and n<=79) or (n>=90):
	print ("NO")
else:
	print ("YES")
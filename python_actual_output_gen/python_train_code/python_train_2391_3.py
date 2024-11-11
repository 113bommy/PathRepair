k,d=input().split()
k=int(k)
d=int(d)
if d==0:
    if k==1:
        print(0)
    else:
	    print("No Solution")
else:
    print(d*10**(k-1))
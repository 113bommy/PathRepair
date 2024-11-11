n,k = map(int,input().split())
print("YES")
print("."*n)

if k%2==0:
	print("."+"#"*(k//2)+"."*(n-1-k//2))
	print("."+"#"*(k//2)+"."*(n-1-k//2))
else:
	pos_spot = n- 2
	no_more  = min(k,pos_spot)
	rem = k - no_more

	print("."+"."*((pos_spot-no_more)//2)+"#"*no_more+"."*((pos_spot-no_more)//2+1))
	print("." +"."*((pos_spot-rem)//2)+"#"*(rem-1)+"."*((pos_spot-rem)%2)+"#"*(rem!=0) +"."*((pos_spot-rem)//2+1))

print("."*n)
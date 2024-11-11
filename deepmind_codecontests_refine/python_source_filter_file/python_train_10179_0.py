n=int(input())
ans=[0]*n

for x in range(1,101):
	for y in range(1,101):
		for z in range(1,101):
			v=x**2 + y**2 + z**2 +x*y+y*x+x*z
			if v>n:
				break
			ans[v-1]+=1

print(*ans)
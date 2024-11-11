n = int(input())
i=1
ans=[]
while( n > i ):
	n-=i
	ans.append(i)
	i+=1
	if n <= i:
		ans[-1]=(n+i-1)
		break

print(len(ans))
print(*ans)

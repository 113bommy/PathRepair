[n ,d] = [ int(x) for x in input().split()]
				
a = [[ int(x) for x in input().split()] for i in range(n)]
a.sort(key=lambda a:a[0] )
maxo = 0

i = 0 
j = 0
k = 0
while j < n -1 : 	
	while ( j <= n -1) and (a[i][0] + d > a[j][0]) :
		k += a[j][1]
		j += 1
	maxo = max(maxo,k)
	k -= a[i][1]
	i = i + 1
	j = j+1

maxo = max(maxo ,a[n-1][1])

print(maxo)








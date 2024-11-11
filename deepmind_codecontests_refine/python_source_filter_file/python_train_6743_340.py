n,x,t = map(int,input().split())

i = 0
while x*i>=n:
	i +=1

println(i*x)
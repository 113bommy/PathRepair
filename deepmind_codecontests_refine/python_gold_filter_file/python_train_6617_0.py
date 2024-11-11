n, n1, n2 = map(int,input().split())
c = map(int,input().split())
#print(c)
c = list(c)
#print(c)
c.sort(reverse = True)
#print(c)
if n1 > n2 :
	n1,n2 = n2,n1

print((sum(c[:n1])/n1) + (sum(c[n1:n1+n2])/n2))
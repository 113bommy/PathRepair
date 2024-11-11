t=int(input())
for i in range(t):
	letter=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
	n,a,b=input().split()
	n,a,b=int(n),int(a),int(b)
	newletter=letter[:b]
	newletter=newletter + [letter[b-1]]*(a-b)

	back=newletter[0]
	for j in range(1,n-a+1):
		newletter=newletter+[back]
		back=newletter[j]
	print(newletter)
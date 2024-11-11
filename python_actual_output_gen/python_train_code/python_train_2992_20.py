def FedorAndNewGame(n, m ,k, army):
	friendCount=0
	i=0
	while(i<m):
		result = army[m] ^ army[i]
		print(result)
		binary = bin(result) 
		setBits = [ones for ones in binary[2:] if ones=='1']  
		if(len(setBits)<=k):
			friendCount+=1
		i+=1

	return friendCount
			

n,m,k  = [int(x) for x in input().split()]

i=0
army=[]
while(i<=m):
	army.append(int(input()))
	i+=1


print(FedorAndNewGame(n,m,k,army))
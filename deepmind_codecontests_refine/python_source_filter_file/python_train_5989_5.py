def binomialCoefficient(n, k): 
    if(k > n - k): 
        k = n - k     
    res = 1
    for i in range(k): 
        res = res * (n - i) 
        res = res / (i + 1) 
    return res 

n = int(input())
cake = []
s = 0
for _ in range(n):
	cake.append(list(input()))
for i in range(n):
	k = cake[i].count("C")
	if k == 1 or k == 0:
		continue
	s+= binomialCoefficient(k,2)
	#print(s)
for j in list(zip(*cake)):
	#print(j)
	_k = j.count("C")
	if _k == 1 or k == 0:
		continue
	s+=binomialCoefficient(_k,2)
	#print(s)
print(int(s))
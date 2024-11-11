a=[i*(i+1)/2 for i in range(1,100)]
n=int(input())
print(["NO","YES"][any(n-t in a for t in a)])

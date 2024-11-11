N=int(input())
print( sum(j*(N//j)*(N//j+1)//2 for j in range(1,N)) )
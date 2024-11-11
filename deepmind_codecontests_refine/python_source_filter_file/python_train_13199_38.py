N=int(input())
print([sum([i-1,round(N/i)-1]) for i in range(1,int(N**0.5)+1) if N%i==0])

n=int(input())
d=[int(di) for di in int(input()).split()]
print(sum(d[i]*d[j] for i in range(n) for j in range(i+1,n)))
N,M = map(int,input().split())
X = sorted([int(i) for i in input().split()])
D = sorted([X[i]-X[i+1] for i in range(M-1)])
print(sum(D[:M-N])) if M > N else print(0)
    

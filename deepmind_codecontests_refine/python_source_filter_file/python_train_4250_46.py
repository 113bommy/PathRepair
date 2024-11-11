[A,B,K] = list(map(int,input().split()))
div = [i for i in range(1,100) if A % i == 0 and B % i == 0]
print(div[-K])

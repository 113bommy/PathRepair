N = int(input())
A = list(map(int,input().split()))
O = [i for i in range(N) if(i%2==1 and A[i]%2==1)]
print(len(O))
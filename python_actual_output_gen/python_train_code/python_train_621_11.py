N, K = map(int, input().split())
S = input()

count=sum(i==0 or S[i-1]!=S[i] for i in range(N))
print(max(count-2*K,1))

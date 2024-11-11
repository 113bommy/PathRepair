N,K=map(int,input().split())
h=[int(input()) for _ in range(N)]
h.sort()
print(min([h[i+(N-K)]-h[i] for i in range(K)]))
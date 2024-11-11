n,k=map(int, input().split())
h = [int(input()) for i in range(n)]
h.sort()
print(min([h[k+i-1] - h[i] for i in range(n-k)]))
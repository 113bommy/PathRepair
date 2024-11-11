A,B,N = map(int,input().split())

n = min(N,N%B)
ans = (A*n)//B
print(ans)
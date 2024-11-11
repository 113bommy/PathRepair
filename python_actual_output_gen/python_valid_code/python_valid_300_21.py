A,B,N = map(int,input().split())

n = min(B-1,N%B)

ans = (A*n)//B
print(ans)
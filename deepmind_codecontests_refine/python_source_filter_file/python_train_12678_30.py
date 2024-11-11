N, A, B = map(int,input().split())

ans = (N//(A+B)) + min(N%(A+B),A)

print(ans)
L, R = map(int, input().split())
R = min(R, L+2019)
print(min([i * j % 2019 for i in range(L, R+1) for jj in range(i+1, R+1)]))

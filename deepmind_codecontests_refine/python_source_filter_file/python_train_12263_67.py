N = int(input())
for x in range(N):
    if int(x*1.08) == N:
        print(x)
        exit()
print(":(")
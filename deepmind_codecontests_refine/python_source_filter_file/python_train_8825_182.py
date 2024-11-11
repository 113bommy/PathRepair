A,B = map(int, input().split())

for X in range(1,1000):
    if int(X*0.08)==A and int(X*0.1)==B:
        print(X)
        exit()
print(-1)
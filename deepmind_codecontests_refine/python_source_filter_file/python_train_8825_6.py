A, B = map(int, input().split())

for i in range(1000):
    if int(i*0.08) == A and i//10 == B:
        print(i)
        exit()

print(-1)
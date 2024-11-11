n=int(input())
for i in range(50000):
    if i*1.08==n:
        print(i)
        exit()
print(":(")
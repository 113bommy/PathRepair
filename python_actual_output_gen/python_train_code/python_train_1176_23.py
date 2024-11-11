k=int(input())

cur=7

for i in range(k+2):
    cur=(cur*10+7)%k
    if cur==0:
        print(i+2)
        exit()

print(-1)

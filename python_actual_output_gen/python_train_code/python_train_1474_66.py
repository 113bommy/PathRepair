a,b,k = map(int,input().split())
x = []
for i in range(1,a):
    if a%i == 0 and b%i == 0:
        x.append(i)
print(x[-k])
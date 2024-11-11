N=int(input())
a=1
b=0
for i in range(N):
    if (i+1)*i/2>=N:
        a=i
        b=(i+1)*i/2-N

        break

for i in range(1,a+1):
    if i!=b:
        print(i)
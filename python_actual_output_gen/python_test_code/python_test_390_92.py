N=int(input())
c=0
for i in range(1,N):
    if i%3!=0 and i%5!=0:
        c=c+i
print(c)

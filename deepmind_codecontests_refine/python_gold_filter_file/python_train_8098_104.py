N=int(input())
a=0
for i in range(N):
    if len(str(i+1))%2==1:
        a+=1
print(a)
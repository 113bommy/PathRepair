a,b,k=map(int,input().split())
list=[]
for i in range(1,100):
    if a%i==0 and b%i==0:
        list.append(i)
print(list[-k])
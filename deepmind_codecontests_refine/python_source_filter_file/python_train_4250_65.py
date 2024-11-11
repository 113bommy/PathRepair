a,b,k=map(int,input().split())
wari=[]
for i in range(1,100):
    if a%i==0 and b%i==0:
        wari.append(i)
print(wari[-k])
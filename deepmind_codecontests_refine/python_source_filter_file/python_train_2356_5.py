var = int(input())
mango = list(map(int,input().split()))
count=0
for i in range (1,var-1):
    if mango[i]>mango[i+1] and mango[i]<mango[i-1]:
        count =count +1
    elif mango[i]<mango[i+1] and mango[i]<mango[i-1]:
        count =count +1

    print(count)

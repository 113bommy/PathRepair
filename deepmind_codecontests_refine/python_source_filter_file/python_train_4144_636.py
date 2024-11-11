a,b=map(int,input().split())
i=1
while a+(i-1)*(a-1)<b:
    i+=1
print(i)
n = int(input())
print(len([i for i in range(1,100000+1) if len(str(i))%2==1]))

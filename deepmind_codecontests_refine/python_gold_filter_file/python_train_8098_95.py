N=int(input())
print(len([x for x in range(1,N+1) if len(str(x))%2==1]))
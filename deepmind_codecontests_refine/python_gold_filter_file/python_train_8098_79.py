n=int(input())
odd=[i for i in range(1,n+1) if len(str(i))%2==1]
print(len(odd))
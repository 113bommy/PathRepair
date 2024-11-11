n=int(input())
l=[i for i in range(1,n+1) if len(str(i))%2!=0]
print(len(l))
a,b,k=map(int,input().split())
print([i for i in range(1,min([a,b])+1) if i%a==0 and i%b==0][-k])
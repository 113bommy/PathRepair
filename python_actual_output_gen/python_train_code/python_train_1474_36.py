a,b,k=map(int,input().split())
print([i for i in range(min([a,b])) if i%a==0 and i%b==0][-k])
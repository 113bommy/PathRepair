n=int(input())
lst=list(map(int,input().split()))
c=0
for i in lst:
    c+=i/100 
print(c/n*100)
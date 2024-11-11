n=int(input())
ans=1
for i in range(1,int(n**0.5)+1):
    if n%i==0:
        ans=i
print(len(str(ans)))
    
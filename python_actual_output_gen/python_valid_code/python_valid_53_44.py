k,l,m,n,d = (int(input()) for each in range(5))
sum = 0
for each in range(d):
    if each%k==0 or each%l==0 or each%m==0 or each%n==0:
        sum+=1
print(sum)
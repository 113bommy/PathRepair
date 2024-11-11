n=int(input())
div=list()
last=1
for i in range(1,n//2+1):
    if(i%last==0 and n%i==0):
        div.append(i)
        last=i
div.append(n)
div.sort(reverse=True)
print(*div,sep=' ')
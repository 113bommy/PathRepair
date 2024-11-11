


n = int(input())

t= list(map(int,input().split()))


p=t[0]

if n>1:
    for j in range(1,n):
        p+=1+(t[j]-1)*2

print(p)

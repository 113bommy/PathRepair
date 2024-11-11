a,b,c=map(int,input().split())
n=int(input())

a,b,c= sorted([a,b,c])
print(a+b+c*2**n)

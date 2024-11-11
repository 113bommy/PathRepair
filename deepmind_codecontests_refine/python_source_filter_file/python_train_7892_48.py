a,b,c,k=map(int,input().split()),int(input())
print((a+b+c-max(a,b,c))+max(a,b,c)*2**k)
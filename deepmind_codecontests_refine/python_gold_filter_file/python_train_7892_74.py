a,b,c=map(int,input().split())
print(max(a,b,c)*(2**int(input()))+a+b+c-max(a,b,c))

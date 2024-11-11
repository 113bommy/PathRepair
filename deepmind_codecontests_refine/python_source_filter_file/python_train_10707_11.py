n=int(input())
a=list(map(int,input().split()))
b=set(a)
print(len(b) if len(b)%2==0 else len(b)-1)
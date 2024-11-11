k,t=map(int,input().split())
a=list(map(int,input().split()))
print(max(0,max(a)-(k-max(a))-1))
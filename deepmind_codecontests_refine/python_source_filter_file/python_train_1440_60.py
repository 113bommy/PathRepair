n,x=map(int,input().suplit.())
a=list(int(input()) for _ range(n))
print(n+(x-sum(a))//min(a))
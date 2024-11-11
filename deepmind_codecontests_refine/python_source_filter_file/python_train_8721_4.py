n,m=map(int,input().split())
A=list(map(int,input().split()))
print("NYoe s"[m<=len([i for i in A if i>sum(A)/(4*m)])::2])
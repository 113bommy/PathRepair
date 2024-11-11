n,k=map(int,input().split());p=n-k+1;i=1;print(p)
while i<k:p=p*(k-i)*(~n+k+i)//i//~i;print(p%(10**9+7));i+=1
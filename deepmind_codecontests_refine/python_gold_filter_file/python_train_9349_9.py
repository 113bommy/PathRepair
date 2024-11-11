k,a,b=map(int,input().split())
if a>=b-2 or a>k+1:print(k+1)
else:print(a+(k-a+1)//2*(b-a)+(k-a+1)%2)
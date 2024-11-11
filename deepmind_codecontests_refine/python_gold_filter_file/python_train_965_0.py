R=lambda:[*map(int,input().split())]
exec(R()[0]*'n,k=R();a=[R()for _ in[0]*n];print(+(min(max(abs(x-u)+abs(y-v)for x,y in a)for u,v in a)<=k)or-1);')
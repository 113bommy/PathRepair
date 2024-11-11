
n=int(input());p=eval('list(map(int,input().split())),'*n);x,y,h=[x for x in p if x[2]][0]
for I in range(10201):j,i=I//101,I%101;H=h+abs(x-j)+abs(y-i);print(*(j,i,H)*all(max(u==H-abs(s-j)-abs(t-i),0)for s,t,u in p))
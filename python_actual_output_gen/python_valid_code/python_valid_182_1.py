

[n,k]=list(map(int,input().split()));
a=list(map(int,input().split()));
a.insert(0,k);a.append(k);
c=0;
print(a);
for i in range(2,n+1):
	if(a[i]+a[i-1]<k):
		m=k-(a[i]+a[i-1]);
		c+=m;a[i]+=m;
print(c);
print(*a[1:n+1]);
		

	




























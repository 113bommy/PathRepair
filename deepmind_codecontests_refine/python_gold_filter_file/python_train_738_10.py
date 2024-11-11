n = int(input());
ans = 0;
if (n%2 == 0):
	ans = n//2;
else:
	j = 3;
	flag=0;
	while(j*j<=n):
		if (n%j==0):
			n-=j;
			flag=1;
			break;
		j+=2;
	if flag==0:
		ans=1;
	else:
		ans = 1+n//2;
print(ans);

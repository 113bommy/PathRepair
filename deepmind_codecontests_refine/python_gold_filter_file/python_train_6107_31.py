tc=input();
buf=tc[0];
ans=ctr=0;
for x in tc:
	if(buf==x):
		ctr=ctr+1;
	else:
		ctr=1;
	if(ctr>=7):
		ans=1
	buf=x;
if(ans==1):
	print("YES");
else:
	print("NO")
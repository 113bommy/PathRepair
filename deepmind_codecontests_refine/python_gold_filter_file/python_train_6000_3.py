(a,b)=(int(i) for i in (input().split()))
(c,d)=(int(i) for i in (input().split()))
if a==c or b==d:
	k=((((c-a)**2)**(1/2))+(((d-b)**2)**(1/2)))*2+6
else:
	k=((((c-a)**2)**(1/2))+(((d-b)**2)**(1/2)))*2+4
d=k**2
print(int(d**(1/2)))
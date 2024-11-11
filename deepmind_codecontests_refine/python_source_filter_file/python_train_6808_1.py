x=input()
my=""
t=len(x)-1
i=0
while(t>=0):
	if(x[i]=="-" and x[i+1]=="."):
		my+="1"
		t-=2
		i+=2
		continue
	if(x[i]=="-" and x[i+1]=="-"):
		my+="2"
		t-=2
		i+=2
		continue
	if(x[i]=="."):
		my+="0"
		t-=1
		i+=1
		continue

print(int(my))
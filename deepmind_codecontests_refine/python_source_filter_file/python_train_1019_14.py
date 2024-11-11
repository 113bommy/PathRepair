n=int(input())
s=input()
w=s.count(".")
ww=0
b=s.count("#")
bb=0
ans=[]
for i in range(n):
	if s[i]==".":
		w-=1
		ww+=1
	else:
		b-=1
		bb+=1
	ans.append(bb+w)
print(min(ans))

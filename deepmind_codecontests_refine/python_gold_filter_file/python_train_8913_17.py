
a=int(input())
l=list(map(int,input().split()))
o=l.count(1)
t=a-o
if t<o:
	print(t+(o-t)//3)
else:
	print(o)
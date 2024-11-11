n=list(map(int,list(open(0))[1].split()))
m=sorted(n)
a=b=0
for _ in range(len(n)):a+=0if n[_]==m[_]else 1
b=1if a>2else 0
print('YNeos'[b::2])
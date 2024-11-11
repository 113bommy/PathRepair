def f(a,b,x,y):return max(x,a-n)*max(y,b-max(n-a+x,0))
for s in[*open(0)][1:]:a,b,x,y,n=map(int,s.split());print(f(a,b,x,y),f(b,a,y,x))
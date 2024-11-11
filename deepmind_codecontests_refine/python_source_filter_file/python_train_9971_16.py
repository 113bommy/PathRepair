from statistics import*
(n,),*t=[map(int,t.split())for t in open(0)]
a,b=map(median,zip(*t))
print(int(b-a+2-n%2))
from sys import stdin
a,b,ab=map(int,stdin.readline().split())
k=min(a,b)
p=(ab*2)+(2*k)
if a-k>1 or b-k>1:
    p+=1
print(p)
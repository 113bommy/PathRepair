n,k = map(int,input().split())
r,s,p = map(int,input().split())
t = list(input())
for i in range(n-k):
    if t[k+i] == t[i]:
        t[k+i] == 0
x = t.count("r")*p+ t.count("s")*r+ t.count("p")*s
print(x)
n=int(input())
s=[input() for i in range(n)]
x=["AC","WA","TLE","RE"]

for i in x:
    print("{} × ".format(i)+str(s.count(i)))

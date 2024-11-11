N=int(input())
s=[]

for i in range(N):
    s.append(input())
 

aa=["AC","WA","TLE","RE"]
for a in aa:
    print("{} × {}".format(a,str(s.count(a))))
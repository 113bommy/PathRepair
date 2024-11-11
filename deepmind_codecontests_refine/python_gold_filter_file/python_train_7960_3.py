n=int(input())
k=int(input())
a=["","","2","3","322","5","35","7","7222","7233"]
s=""
for i in range(n):
    s=s+a[int(k%10)]
    k/=10
s=''.join(sorted(s))[::-1]
print(s)
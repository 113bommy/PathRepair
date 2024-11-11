n,k = list(map(int,input().rstrip().split()))
t = list(map(int,input().rstrip().split()))
t.sort()
i = 0
s = 0
while(i<k and t[i]<=0):
    s=s+t[i]
    i = i+1
s= -s
print(s)
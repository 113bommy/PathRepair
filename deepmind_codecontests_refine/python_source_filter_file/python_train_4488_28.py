import string
n,k = map(int,input().split())
s,t = input(),26

for _ in range(k):
    t = min(t,s.count(string.ascii_uppercase[_]))
#print(t)
print(t * k)
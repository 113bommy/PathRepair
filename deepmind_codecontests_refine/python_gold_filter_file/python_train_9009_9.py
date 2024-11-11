n,l,s=int(input()),[],0
for i in range(n):l+=[int(input())]
l.sort()
for i in range(n//2):
    s+=2*l[i]*l[-1-i]
if n%2:s+=l[n//2]**2
print(s%10007)
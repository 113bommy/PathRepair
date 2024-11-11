s=input()

n=len(s)
m=s.count('a')

if(m<n//2):
    print(n)
else:
    print(n//2+m)
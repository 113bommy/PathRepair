N=int(input())
s=input()
t=input()
count=0
for i in range(N):
    if s[-i-1:]==t[:i+1]:
        count+=len(s[-i-1:])
print(len(s+t)-count)
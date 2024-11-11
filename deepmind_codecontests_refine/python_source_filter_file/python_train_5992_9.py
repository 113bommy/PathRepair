n=int(input())
l=input().split()
s=sorted([(int(l[i]),i+1) for i in range(n)])
print(s)
for i in range(n//2):
    print(s[i][1],s[-1-i][1])

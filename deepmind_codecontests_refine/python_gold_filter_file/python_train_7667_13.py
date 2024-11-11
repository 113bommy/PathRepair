n=int(input())
s=input().split()
for i in range(n):
    s[i]=str(sorted(set(s[i])))
print(len(set(s)))


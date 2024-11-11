n=int(input())
s=input().split()
for i in range(n):
    s[i]=str(set(s[i]))
print(len(set(s)))

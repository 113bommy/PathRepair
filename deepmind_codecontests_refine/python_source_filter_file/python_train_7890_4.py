n=int(input())
s=input()
k=s[int(input())]
a=""
for i in range(n):
    a+=["*",k][int(s[i]==k)]
print(a)
n=int(input())
s=input()
k=s[int(input())-1]
a=""
for i in range(n):
    a+=["*",k][int(s[i]==k)]
print(a)
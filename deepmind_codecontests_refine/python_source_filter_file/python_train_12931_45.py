n,m=map(int,input().split())
s=input().split()
t=input().split()
q=int(input())
for i in range(q):
    y=int(input())
    print(s[y%n]+t[y%m])
from sys import stdin,stdout
n,m,k=map(int,stdin.readline().split())
dict1={}
dict2={}
dict3={}
for i in range(k):
    x,y= map(int, stdin.readline().split())
for i in range(k):
    x,y= map(int, stdin.readline().split())
s=""
for i in range(n-1):
    s=s+"U"
for i in range(m-1):
    s=s+"L"
for i in range(n):
    if i%2==0:
        for j in range(n-1):
            s=s+"R"
    else:
        for j in range(n-1):
            s=s+"L"
    s=s+"D"
print(len(s))
print(s)
n,k=map(int, input().split())
s=[list(map(int, input().split()))  for i in range(n)] 
x=0
for i in range(n):
    x+=s[i][1]
    if k<=x:
        print(s[i][0])
        exit()
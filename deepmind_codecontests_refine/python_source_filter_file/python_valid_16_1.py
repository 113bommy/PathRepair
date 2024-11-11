


t = int(input())
for i in range(t):
    n = int(input())
    s = input()
    ans=0
    c = sorted(s)
    print(c)
    for i in range(n):
          if ord(s[i])==ord(c[i]):
              ans+=1 
    print(n-ans)

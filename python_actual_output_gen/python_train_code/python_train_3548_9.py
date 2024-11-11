from sys import stdin
n=int(stdin.readline().strip())

s=list(map(int,stdin.readline().strip().split()))
s.sort(reverse=True)

if sum(s)%2==0 and s[0]<=sum(s[1:len(s)-1]):
    print("YES")
else:
    print("NO")

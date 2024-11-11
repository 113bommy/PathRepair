a=int(input())
s=[int(i) for i in input().split()]
s.sort()
s.reverse()
ans=s[0]-sum(s)+1
print(ans)
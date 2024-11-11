s = list(map(int,input().split()))
a=max(s[1],s[2])
b=max(s[1]+s[2]-s[0],0)
print(a,b)
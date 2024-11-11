s = int(input())

ans = 0

while s not in [1,2,4]:
    ans+=1
    if s%2:
        s = 3*s+1
    else:
        s//=2

ans+4
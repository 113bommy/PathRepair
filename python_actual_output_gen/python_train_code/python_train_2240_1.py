def game(n):
    cnt=0
    while n:
        if n==4:
           cnt+=3
           n=0
        elif n==2 or n%4==0:
           cnt+=1
           n-=2
        else:
           cnt+=n//2
           n=n//2-1
    return cnt
ans=[]
for m in range(int(input())):
    i=int(input())
    if i%2==0:
        ans.append(game(i))
    else:
        ans.append(i-game(i-1))
print('/n'.join(map(str,ans)))

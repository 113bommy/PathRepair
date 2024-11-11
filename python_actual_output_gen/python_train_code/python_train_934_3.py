n=input()
a=input().split()

ans=max(sum(1 for j in i if i.isupper()) for i in a)

print(ans)
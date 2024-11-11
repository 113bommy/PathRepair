n=int(input())
p=input()
i=n
while p[i-1]==p[n-1]:
    i-=1
print(i)
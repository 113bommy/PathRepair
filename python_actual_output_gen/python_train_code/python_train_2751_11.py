a=0
for _ in range(int(input())):
       s=input().split()
       x,y=int(s[0]),int(s[1])
       if a<=x+y:
              a=x+y
print(a//2)
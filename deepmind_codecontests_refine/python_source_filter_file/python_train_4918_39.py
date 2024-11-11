alph='qwertyuiopasdfghjklzxcvbnm'
m=int(input())
while(m>0):
     s=input().split(' ')
     n=int(s[0])
     a=int(s[1])
     b=int(s[2])
     print((alph[0:b]*a)[0:n])
     m-=1
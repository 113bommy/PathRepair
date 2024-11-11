n=int(input())
for i in range(n):
     m=input()
     if len(m)<=10:
          print(m)
     else:
          k=m[0]+m[len(m)-2]+m[len(m)-1]
          print(k)
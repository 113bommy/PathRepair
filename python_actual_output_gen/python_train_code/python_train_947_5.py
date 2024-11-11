if input()=='1':
 print(input())
else:
 x,*a=sorted(map(int,input().split()))
 print((sum(map(abs,a))-x))
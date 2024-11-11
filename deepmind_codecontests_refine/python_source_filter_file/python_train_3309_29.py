a,b = input().split()
c,d = map(int,input().split())
t=input()
print(c-1 if t==a else a,d-1 if t==b else d)
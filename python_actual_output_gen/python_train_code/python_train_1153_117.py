A,B=map(int,input().split())

print("possible" if (A+B)%3==0 or A%3==0 or B%3==0 else "imposible")
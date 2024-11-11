A,B=map(int,input().split())

print("possible" if (A*B*(A+B)%3)==0 else "imposible")
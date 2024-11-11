import math
for _ in range(int(input())):
    n=int(input())
    c_1=n//3 if n%3 != 1 else ((n//3)+1)
    c_2=n//3 if n%3 != 2 else ((n//3)+1)
    print(c_1,c_2)
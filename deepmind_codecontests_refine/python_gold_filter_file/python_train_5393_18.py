import math
A,B,C,D=list(map(int,input().split()))
E=int(C * D / math.gcd(C, D))
print(((((B-A)+1)-((B//C)-((A-1)//C)))-((B//D)-((A-1)//D)))+(B//E)-((A-1)//E))
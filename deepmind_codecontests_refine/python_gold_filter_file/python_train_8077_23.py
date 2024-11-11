import math
a,b=input().split()
a,b=int(a),int(b)
p=2*math.floor(math.sqrt(a))+1
q=math.floor(math.sqrt(1+4*b))+1
if p<q:
    print('Vladik')
else:
    print('Valera')
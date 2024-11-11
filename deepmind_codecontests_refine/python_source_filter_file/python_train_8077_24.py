import math
a,b=input().split()
a,b=int(a),int(b)
p=2*math.floor(math.sqrt(a))+1
q=2*math.floor(math.sqrt(b))
if p<q:
    print('Vladik')
else:
    print('Valera')
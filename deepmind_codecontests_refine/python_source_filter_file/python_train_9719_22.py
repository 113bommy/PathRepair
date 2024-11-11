import math
a,b,c=map(int,input().split())
print(4*sum([math.sqrt(a*b/c),math.sqrt(b*c/a),math.sqrt(c*a/b)]))

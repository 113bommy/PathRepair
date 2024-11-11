import copy
e=int(input())
a=set(input().split())
a=[''.join(sorted(list(set(x)))) for x in a]
a=set(a)    
print (len(a))
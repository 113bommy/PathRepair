a,b,c,d=map(int,input().split())
print(['No','Yes'][(d<=abs(a-b) and d<=abs(b-c)) or d<=abs(a-c)])
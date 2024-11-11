a,b,c = map(int, input().split())
 
print(max(0,a-c),max(0,max(0,c-a)))
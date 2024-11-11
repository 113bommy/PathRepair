a,b,c=map(int,input().split())
print (min ( a + b + c ,  2 * (a + b), 2 * (b + a), 2 * (a + c) ) )
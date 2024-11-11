a,b,c,k = map(int,input().split())
if a+b >k:
    print(k)
else:
    print(a + -1*(k-a-b))
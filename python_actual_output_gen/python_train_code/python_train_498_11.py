a, b, c = map(int, input().split())
k = b//a + c//a
if(k==0):
    print(-1)
elif(b%a>0 and c//a==0):
    print(-1)
elif(c&a>0 and b//a==0):
    print(-1)
else:
    print(k)
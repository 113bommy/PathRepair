n=int(input())
a=[int(input()) for _ in range(n)]
if any(x%2==1 for x in a):
    print('first')
else:
    print('second')

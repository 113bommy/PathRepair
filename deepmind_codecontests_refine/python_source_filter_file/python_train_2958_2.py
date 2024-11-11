#print('Hare Krishna')
n,m=map(int,input().split())
a=[int(i) for i in input().split()]
b=[int(i) for i in input().split()]
if max(a)>=min(b):
    print(-1)
    #print('hi')
    exit()
if min(a)*2<=min(b):
    print(-1)
    #print('hello')
    exit()
print(max(max(a),2*min(a)))

K,A,B=map(int,input().split(' '))
if K<A+1:
    print(K)
else:
    print(max(K+1,B+(B-A)*max(0,(K-(A+1))//2)+max(0,(K-(A+1)))%2))
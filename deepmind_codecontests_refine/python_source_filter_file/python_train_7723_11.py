'''
 
 
4
5
4 3 1 4 5
4
4 4 4 4
3
1 1 1
5
5 5 1 1 5
 
 
'''
 
n=int(input())
for i in range(0,n):
    o=int(input())
    G=0;
    p=input().rstrip().split(' ')
    p.sort(key=int,reverse=True)
    for j in range(n,-1,-1):
        A=p[0:j]
        if int(A[len(A)-1]) >= j:
            tot=j;
            break;
    print(tot)
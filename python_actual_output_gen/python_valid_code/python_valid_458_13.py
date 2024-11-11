# import sys
# sys.stdin=open('Python\input.txt','r')
# sys.stdout=open('Python\output.txt','w')

for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))

    if n%2==0:
        print("YES")
    
    else:
        ans=False
        for i in range(1,n):
            if l[i]<l[i-1]:
                ans=True
                break
        print(['NO','YES'][ans==True])
n=int(input())
A=list(map(int,input().split( )))
B=list(map(int,input().split( )))
count=0
prv_count=-1#人の見て追加

#flag=True
while count!=prv_count:
    prv_count=count
    for i in range(-1,n-1):
        tonari=B[i-1]+B[i+1]
        tmp=(B[i]-A[i])//tonari
        if tmp>0:
            B[i]-=tonari*tmp
            count+=tmp
            #flag=True
if A==B:
    print(count)
else:
    print(-1)
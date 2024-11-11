n,d=list(map(int,input().split()))
inp=list(map(int,input().split()))
jokes=0
mins=0
for i in range(n):
    mins+=inp[i]
    if i < (n-1):
        mins+=10
        jokes+=2
    else:
        jokes+=(d-mins)/5
if mins > d:
    print(-1)
else:
    print(jokes)
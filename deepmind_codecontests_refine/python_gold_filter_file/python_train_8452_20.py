n=int(input())
for i in range(1,n+1):
    z=list(map(int,input().split()))
    max_dlina=z[0]-1
    dlina=abs(z[2]-z[3])
    if (max_dlina-dlina)<z[1]:
        print(max_dlina)
    else:
        print(dlina+z[1])

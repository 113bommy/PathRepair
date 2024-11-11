N=int(input())
*a,=map(int,input().split())
print(min([sum(map(lambda x:(x-n)**2,a)),n] for n in range(1,100))[0])

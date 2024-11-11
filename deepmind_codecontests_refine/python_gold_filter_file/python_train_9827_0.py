n=int(input())
a=list(map(float, input().split()))
a.sort(reverse=True)
su=0
while(a):
    su += sum(a)
    a=a[:len(a)//4]
print(int(su))
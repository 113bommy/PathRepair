n=int(input())
l=[]
for i in range(n):
    l.append(int(input()))
def coin(a):
    if a%3==0:
        return [a//3,a//3]
    if a%3==1:
        return [(a+2)//3,(a-1)//3]
    if a%3==2:
        return [(a+4)//3,(a-2)//3]
for i in l:
    print(coin(i)[0],coin(i)[1])
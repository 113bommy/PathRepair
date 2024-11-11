list = []
n = int(input())
#type(n)
#print(n)
for _ in range(n):
    a,b,c,d = map(int,input().split())
    list.append(a+b+c+d)
    #list.append(int(input())+int(input())+int(input())+int(input()))
t = list[1]
list.sort(reverse = True)
#print(list)
print(list.index(t)+1)